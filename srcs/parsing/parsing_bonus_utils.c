/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:57:42 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/23 16:31:19 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../vector/vector.h"

int	get_material_input_size(char *material)
{
	if (ft_strcmp(material, P_REFLECT) == 0)
		return (0);
	else if (ft_strcmp(material, P_PHONG) == 0)
		return (2);
	else if (ft_strcmp(material, P_FRESNEL) == 0)
		return (1);
	else if (ft_strcmp(material, P_UV) == 0)
		return (0);
	else if (ft_strcmp(material, P_SPECIAL) == 0)
		return (1);
	else
		ft_print_exit();
	return (0);
}

int	get_valid_input_size(t_node *node, char **strs)
{
	if (node->type == SPHERE)
		return (SPHERE_SIZE + get_material_input_size(strs[SPHERE_SIZE - 1]));
	else if (node->type == PLANE)
		return (PLAIN_SIZE + get_material_input_size(strs[PLAIN_SIZE - 1]));
	else if (node->type == CYLINDER)
		return (CYLINDER_SIZE + \
			get_material_input_size(strs[CYLINDER_SIZE - 1]));
	else if (node->type == CONE)
		return (CONE_SIZE + get_material_input_size(strs[CONE_SIZE - 1]));
	else
		ft_print_exit();
	return (0);
}

int	get_shape_size(t_node *node)
{
	if (node->type == SPHERE)
		return (SPHERE_SIZE);
	else if (node->type == PLANE)
		return (PLAIN_SIZE);
	else if (node->type == CYLINDER)
		return (CYLINDER_SIZE);
	else if (node->type == CONE)
		return (CONE_SIZE);
	else
		ft_print_exit();
	return (0);
}
