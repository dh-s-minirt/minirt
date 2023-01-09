/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:36 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/09 15:26:02 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#define _DATA_LEN 6

void	init_cylinder(char **strs, t_info_data *data);

static const char	*g_data[6] = {
	"A", "C", "L", "pl", "sp", "cy"
};

static void (*const	g_functions[6])(char **, t_info_data *) = {
	init_am_light, init_camera, init_light, \
		init_plane, init_sphere, init_cylinder
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
	data->nor_vector = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	data->diameter = ft_atof(strs[3]);
	data->radius = data->diameter / 2.0;
	data->height = ft_atof(strs[4]);
	tmp = ft_split(strs[5], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	data->color = vec(ft_atof(tmp[0]) / 255.999, ft_atof(tmp[1]) / 255.999, \
		ft_atof(tmp[2]) / 255.999);
	ft_release_strs(tmp);
}

void	init_cylinder(char **strs, t_info_data *data)
{
	t_cylinder	*cylinder;
	t_node		*node;

	if (ft_strs_size(strs) != 6)
		ft_print_exit();
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit(0);
	fill_cylinder(cylinder, strs);
	node = node_new((void *)cylinder, CYLINDER);
	node_add_back(&data->shape, node);
}

void	fill_data(char *line, t_info_data *data, int *cnt)
{
	char				**strs;
	int					i;
	static int			check[6] = {0, 0, 0, 0, 0, 0};

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
	if (0 <= i && i <= 2)
	{
		check[i] += 1;
		(*cnt) += 1;
	}
	g_functions[i](strs, data);
}

void	get_info_data(char *filename, t_info_data *data)
{
	int			fd;
	char		*line;
	int			cnt;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_print_exit();
	line = get_next_line(fd);
	cnt = 0;
	while (line)
	{
		if (*line != '\n')
			fill_data(line, data, &cnt);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (cnt < 3)
		ft_print_exit();
	fill_camera_data(data);
}
