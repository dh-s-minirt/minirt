/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:57:06 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/01/31 20:10:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_sphere(t_sphere *sphere, char **strs)
{
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	sphere->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	sphere->diameter = ft_atof(strs[2]);
	sphere->radius = sphere->diameter / 2.0;
	tmp = ft_split(strs[3], ',');
	sphere->color = vec(ft_atof(tmp[0]) / 255.999, ft_atof(tmp[1]) / 255.999, \
		ft_atof(tmp[2]) / 255.999);
	ft_release_strs(tmp);
}

void	init_sphere(char **strs, t_info_data *data)
{
	t_sphere	*sphere;
	t_node		*node;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		exit(0);
	fill_sphere(sphere, strs);
	node = node_new((void *)sphere, SPHERE);
	node_add_back(&data->objects, node);
}

void	fill_plane(t_plane *plain, char **strs)
{
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	plain->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	plain->nor_vector = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[3], ',');
	plain->color = vec(ft_atof(tmp[0]) / 255.999, ft_atof(tmp[1]) / 255.999, \
		ft_atof(tmp[2]) / 255.999);
	ft_release_strs(tmp);
}

void	init_plane(char **strs, t_info_data *data)
{
	t_plane		*plane;
	t_node		*node;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		exit(0);
	fill_plane(plane, strs);
	node = node_new((void *)plane, PLANE);
	node_add_back(&data->objects, node);
}


void	init_am_light(char **strs, t_info_data *data)
{
	char			**color_data;
	double			ratio;
	t_light_node	*node;
	t_am_light		*am_light;

	if (ft_strs_size(strs) != 3)
		ft_print_exit();
	ratio = ft_atof(strs[1]);
	color_data = ft_split(strs[2], ',');
	if (ft_strs_size(color_data) != 3)
		ft_print_exit();
	am_light = malloc(sizeof(t_am_light));
	if (!am_light)
		exit(EXIT_FAILURE);
	am_light->color = vec_mul(vec(ft_atof(color_data[0]) / 255.999, \
	ft_atof(color_data[1]) / 255.999, ft_atof(color_data[2]) / 255.999), ratio);
	node = new_light_node((void *)am_light, AM_LIGHT);
	light_node_add_back(&data->light_node, node);
	ft_release_strs(color_data);
}
