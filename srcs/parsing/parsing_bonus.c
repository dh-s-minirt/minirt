/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:14:11 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/23 16:30:41 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../vector/vector.h"

void	add_material_data(t_node *node, char **strs)
{
	char	*material;

	if (ft_strs_size(strs) != get_valid_input_size(node, strs))
		ft_print_exit();
	material = strs[get_shape_size(node) - 1];
	if (ft_strcmp(material, P_REFLECT) == 0)
		add_reflect(node);
	else if (ft_strcmp(material, P_PHONG) == 0)
		add_phong(node, strs);
	else if (ft_strcmp(material, P_FRESNEL) == 0)
		add_fresnel(node, strs);
	else if (ft_strcmp(material, P_UV) == 0)
		add_uv(node);
	else if (ft_strcmp(material, P_SPECIAL) == 0)
		add_special(node, strs);
}

void	fill_ms(char **strs, t_ms *ms)
{
	char	**tmp;

	if (ft_strcmp(strs[1], "m1") == 0)
		ms->ms_type = M1;
	else if (ft_strcmp(strs[1], "m2") == 0)
		ms->ms_type = M2;
	else if (ft_strcmp(strs[1], "m3") == 0)
		ms->ms_type = M3;
	else
		ft_print_exit();
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	ms->center = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
}

void	init_ms(char **strs, t_info_data *data)
{
	t_ms	*ms;
	t_node	*node;

	if (ft_strs_size(strs) < MS_SIZE)
		ft_print_exit();
	ms = malloc(sizeof(t_ms));
	if (!ms)
		ft_print_exit();
	fill_ms(strs, ms);
	node = node_new((void *)ms, MS);
	add_material_data(node, strs);
	node_add_back(&data->objects, node);
}
