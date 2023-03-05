/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:21:14 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/06 04:09:58 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../math/math.h"

t_bool	validation_color(t_color data)
{
	if (data.x >= 0 && data.x < 1.0 && data.y >= 0 && data.y < 1.0 \
	&& data.z >= 0 && data.z < 1.0)
		return (TRUE);
	return (FALSE);
}

void	init_light(char **strs, t_info_data *data)
{
	char			**tmp;
	t_light			*light;
	t_light_node	*node;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light = malloc(sizeof(t_light));
	if (!light)
		exit(EXIT_FAILURE);
	light->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	light->ratio = ft_atof(strs[2]);
	tmp = ft_split(strs[3], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light->color = vec(ft_atoi(tmp[0]) / 255.999, \
		ft_atoi(tmp[1]) / 255.999, ft_atoi(tmp[2]) / 255.999);
	if (!validation_color(light->color) || light->ratio <= 0)
		ft_print_exit();
	ft_release_strs(tmp);
	node = new_light_node((void *)light, LIGHT);
	light_node_add_back(&data->lights, node);
}

t_disk	*_make_disk_cy(t_cylinder *cy, t_material mat, t_vec center, \
t_info_data *data)
{
	t_disk		*x;
	t_node		*node;

	x = ft_malloc(sizeof(t_disk));
	x->center = vec_copy(center);
	x->nor_v = vec_mul(cy->nor_vector, -1);
	x->color = vec_copy(cy->color);
	x->r = cy->radius;
	node = node_new((void *)x, DISK);
	node_add_back(&data->objects, node);
	node->material.property = mat.property;
	node->material.m_type = mat.m_type;
	x->parent = cy;
	x->parent_type = CYLINDER;
	return (x);
}
