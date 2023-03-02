/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:36 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/02 14:40:25 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../vector/vector.h"

#define _DATA_LEN 8

void	init_cylinder(char **strs, t_info_data *data);

static const char	*g_data[8] = {
	"A", "C", "L", "pl", "sp", "cy", "cn", "ms"
};

static void (*const	g_functions[8])(char **, t_info_data *) = {
	init_am_light, init_camera, init_light, \
		init_plane, init_sphere, init_cylinder, init_cone,
	init_ms
};

void	fill_cylinder(t_cylinder *data, char **strs)
{
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	data->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	data->nor_vector = vec_unit(vec(ft_atof(tmp[0]), ft_atof(tmp[1]), \
	ft_atof(tmp[2])));
	ft_release_strs(tmp);
	data->diameter = ft_atof(strs[3]);
	data->radius = data->diameter / 2.0;
	data->height = ft_atof(strs[4]);
	tmp = ft_split(strs[5], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	data->color = vec(ft_atof(tmp[0]) / 255.999, ft_atof(tmp[1]) / 255.999, \
		ft_atof(tmp[2]) / 255.999);
	if (!validation_color(data->color))
		ft_print_exit();
	ft_release_strs(tmp);
}

static void	_make_up_bot_disk(t_cylinder *cy, t_info_data *data, \
t_bool	is_water, t_material mat)
{
	t_disk	*up;
	t_disk	*down;
	t_node	*bot;
	t_node	*upper;

	if (is_water)
		return ;
	up = ft_malloc(sizeof(t_disk));
	up->center = vec_add(cy->center, vec_mul(cy->nor_vector, cy->height));
	up->nor_v = vec_copy(cy->nor_vector);
	up->color = vec_copy(cy->color);
	up->r = cy->radius;
	down = ft_malloc(sizeof(t_disk));
	down->center = vec_copy(cy->center);
	down->nor_v = vec_copy(vec_mul(cy->nor_vector, -1));
	down->color = vec_copy(cy->color);
	down->r = cy->radius;
	bot = node_new((void *)down, DISK);
	node_add_back(&data->objects, bot);
	upper = node_new((void *)up, DISK);
	node_add_back(&data->objects, upper);
	bot->material.property = mat.property;
	bot->material.m_type = mat.m_type;
	upper->material.property = mat.property;
	upper->material.m_type = mat.m_type;
}

void	init_cylinder(char **strs, t_info_data *data)
{
	t_cylinder	*cylinder;
	t_node		*node;
	t_bool		is_water;

	if (ft_strs_size(strs) < CYLINDER_SIZE)
		ft_print_exit();
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit(0);
	fill_cylinder(cylinder, strs);
	node = node_new((void *)cylinder, CYLINDER);
	add_material_data(node, strs);
	node_add_back(&data->objects, node);
	if (node->material.m_type == FRESNEL)
		is_water = TRUE;
	else
		is_water = FALSE;
	_make_up_bot_disk(cylinder, data, is_water, node->material);
}

void	fill_data(char *line, t_info_data *data, int *cnt)
{
	char				**strs;
	int					i;
	static int			check[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	strs = ft_split(line, ' ');
	if (!strs || ft_strs_size(strs) == 0)
		ft_print_exit();
	i = 0;
	while (i < _DATA_LEN)
	{
		if (ft_strcmp(strs[0], g_data[i]) == 0)
			break ;
		i++;
	}
	if (i == _DATA_LEN || (0 <= i && i <= 1 && check[i] == 1))
		ft_print_exit();
	if (0 <= i && i <= 1)
	{
		check[i] += 1;
		(*cnt) += 1;
	}
	g_functions[i](strs, data);
	ft_release_strs(strs);
	free(line);
}

void	get_info_data(char *filename, t_info_data *data, int argc)
{
	int			fd;
	char		*line;
	int			cnt;

	if (argc != 2)
		ft_exit("argc error.");
	data->objects = NULL;
	data->lights = NULL;
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		ft_print_exit();
	line = get_next_line(fd);
	cnt = 0;
	while (line)
	{
		if (*line != '\n')
			fill_data(delete_last_newline(line), data, &cnt);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (cnt < 2)
		ft_print_exit();
}
