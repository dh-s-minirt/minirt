/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:57:06 by hyunkyu           #+#    #+#             */
/*   Updated: 2022/12/30 11:30:33 by hyunkyle         ###   ########.fr       */
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
	tmp = ft_split(strs[3], ',');
	sphere->color = create_trgb(0, ft_atoi(tmp[0]), \
			ft_atoi(tmp[1]), ft_atoi(tmp[2]));
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
	node_add_back(&data->shape, node);
}

void	fill_plane(t_plain *plain, char **strs)
{
	char	**tmp;

	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	plain->coordinates = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	plain->nor_vector = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[3], ',');
	plain->color = create_trgb(0, ft_atoi(tmp[0]), \
			ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	ft_release_strs(tmp);
}

void	init_plane(char **strs, t_info_data *data)
{
	t_plain		*plain;
	t_node		*node;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	plain = (t_plain *)malloc(sizeof(t_plain));
	if (!plain)
		exit(0);
	fill_plane(plain, strs);
	node = node_new((void *)plain, PLANE);
	node_add_back(&data->shape, node);
}
