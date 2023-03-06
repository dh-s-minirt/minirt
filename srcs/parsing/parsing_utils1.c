/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:57:06 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/03/06 16:22:21 by idaegyu          ###   ########.fr       */
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
	if (!validation_color(sphere->color))
		ft_print_exit();
	ft_release_strs(tmp);
	sphere->nor_vector = vec(0, 0, 1);
}

void	init_sphere(char **strs, t_info_data *data)
{
	t_sphere	*sphere;
	t_node		*node;

	if (ft_strs_size(strs) < SPHERE_SIZE)
		ft_print_exit();
	sphere = ft_malloc(sizeof(t_sphere));
	fill_sphere(sphere, strs);
	node = node_new((void *)sphere, SPHERE);
	add_material_data(node, strs);
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
	plain->nor_vector = vec_unit(vec(ft_atof(tmp[0]), ft_atof(tmp[1]), \
	ft_atof(tmp[2])));
	ft_release_strs(tmp);
	tmp = ft_split(strs[3], ',');
	plain->color = vec(ft_atof(tmp[0]) / 255.999, ft_atof(tmp[1]) / 255.999, \
		ft_atof(tmp[2]) / 255.999);
	if (!validation_color(plain->color))
		ft_print_exit();
	ft_release_strs(tmp);
}

void	init_plane(char **strs, t_info_data *data)
{
	t_plane		*plane;
	t_node		*node;

	if (ft_strs_size(strs) < PLAIN_SIZE)
		ft_print_exit();
	plane = ft_malloc(sizeof(t_plane));
	fill_plane(plane, strs);
	node = node_new((void *)plane, PLANE);
	add_material_data(node, strs);
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
	if (!validation_color(am_light->color))
		ft_print_exit();
	node = new_light_node((void *)am_light, AM_LIGHT);
	light_node_add_back(&data->lights, node);
	ft_release_strs(color_data);
}
