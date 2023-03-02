/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:07:41 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/02 14:42:34 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../vector/vector.h"
#include "../parsing_ppm/parsing_ppm.h"

void	add_reflect(t_node *node)
{
	t_material	material;

	material.property = NULL;
	material.m_type = REFLECT;
	node->material = material;
}

void	add_phong(t_node *node, char **strs)
{
	t_material		material;
	int				end_idx;
	t_phong_propety	*phong;

	end_idx = get_shape_size(node);
	phong = malloc(sizeof(t_phong_propety));
	if (!phong)
		ft_print_exit();
	phong->kd = ft_atof(strs[end_idx]);
	if (phong->kd < 0 || phong->kd > 1)
		ft_print_exit();
	phong->n = ft_atof(strs[end_idx] + 1);
	phong->ks = 1 - phong->kd;
	material.m_type = PHONG;
	material.property = (void *) phong;
	node->material = material;
}

void	add_fresnel(t_node *node, char **strs)
{
	t_material		material;
	int				end_idx;
	t_fres_property	*fresnel;

	end_idx = get_shape_size(node);
	fresnel = malloc (sizeof (t_fres_property));
	if (!fresnel)
		ft_print_exit();
	fresnel->ior = ft_atof(strs[end_idx]);
	if (fresnel->ior < 1)
		ft_print_exit();
	material.m_type = FRESNEL;
	material.property = (void *) fresnel;
	node->material = material;
}

void	add_uv(t_node *node)
{
	t_material	material;

	material.property = NULL;
	material.m_type = UV;
	node->material = material;
}

void	add_special(t_node *node, char **strs)
{
	t_material			material;
	int					end_idx;
	t_special_property	*special;

	end_idx = get_shape_size(node);
	special = malloc(sizeof (t_special_property));
	if (!special)
		ft_print_exit();
	special->ppm_name = ft_strdup(strs[end_idx]);
	special->ppm = parse_ppm(special->ppm_name);
	material.m_type = SPECIAL;
	material.property = (void *) special;
	node->material = material;
}
