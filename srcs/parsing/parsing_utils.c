/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:26:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/04 17:35:55 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../math/math.h"

char	*delete_last_newline(char *line)
{
	int		size;
	char	*new_line;

	size = ft_strlen(line);
	new_line = malloc(sizeof(char) * size);
	if (!new_line)
		ft_print_exit();
	ft_strlcpy(new_line, line, size);
	return (new_line);
}

void	fill_cone(char **strs, t_cone *cone)
{
	char	**color_data;
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	cone->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	cone->nor_vector = vec_unit(vec(ft_atof(tmp[0]), \
		ft_atof(tmp[1]), ft_atof(tmp[2])));
	ft_release_strs(tmp);
	cone->radius = ft_atof(strs[3]);
	cone->height = ft_atof(strs[4]);
	color_data = ft_split(strs[5], ',');
	if (!color_data || ft_strs_size(color_data) != 3)
		ft_print_exit();
	cone->color = vec(ft_atof(color_data[0]) / 255.999, \
		ft_atof(color_data[1]) / 255.999, ft_atof(color_data[2]) / 255.999);
	if (!validation_color(cone->color))
		ft_print_exit();
	ft_release_strs(color_data);
	cone->theta = atan(cone->radius / cone->height);
}

static t_disk	*_make_bot_disk_cn(t_cone *cn, \
t_info_data *data, t_material mat)
{
	t_disk	*down;
	t_node	*bot;

	down = ft_malloc(sizeof(t_disk));
	down->center = vec_copy((vec_add(cn->center, vec_mul(\
	cn->nor_vector, cn->height))));
	down->nor_v = cn->nor_vector;
	down->color = vec_copy(cn->color);
	down->r = cn->radius;
	bot = node_new((void *)down, DISK);
	node_add_back(&data->objects, bot);
	bot->material.property = mat.property;
	bot->material.m_type = mat.m_type;
	down->parent_type = CONE;
	down->parent = cn;
	return (down);
}

void	init_cone(char **strs, t_info_data *data)
{
	t_cone			*cone;
	t_node			*node;

	if (ft_strs_size(strs) < CONE_SIZE)
		ft_print_exit();
	cone = malloc(sizeof(t_cone));
	if (!cone)
		exit(EXIT_FAILURE);
	fill_cone(strs, cone);
	node = node_new((void *)cone, CONE);
	add_material_data(node, strs);
	node_add_back(&data->objects, node);
	cone->bot = _make_bot_disk_cn(cone, data, node->material);
}

void	init_camera(char **strs, t_info_data *data)
{
	char		**tmp;
	t_camera	camera;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	camera.center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	camera.nor_vector = vec_unit(vec(ft_atof(tmp[0]), ft_atof(tmp[1]), \
	ft_atof(tmp[2])));
	ft_release_strs(tmp);
	camera.fov = ft_atof(strs[3]);
	if (camera.fov <= 0 || camera.fov >= 180)
		ft_print_exit();
	data->camera = camera;
}
