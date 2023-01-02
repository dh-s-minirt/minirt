/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:26:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/02 14:40:01 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_am_light(char **strs, t_info_data *data)
{
	char			**color_data;
	double			ratio;

	if (ft_strs_size(strs) != 3)
		ft_print_exit();
	ratio = ft_atof(strs[1]);
	color_data = ft_split(strs[2], ',');
	if (ft_strs_size(color_data) != 3)
		ft_print_exit();
	data->am_light = vec_mul(vec(ft_atof(color_data[0]) / 255.999, \
	ft_atof(color_data[1]) / 255.999, ft_atof(color_data[2]) / 255.999), ratio);
	ft_release_strs(color_data);
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
	camera.coordinates = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	camera.nor_vector = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	camera.fov = ft_atof(strs[3]);
	data->camera = camera;
}

void	init_light(char **strs, t_info_data *data)
{
	char	**tmp;
	t_light	light;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light.coordinates = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	light.ratio = ft_atof(strs[2]);
	tmp = ft_split(strs[3], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light.color = vec(ft_atoi(tmp[0]) / 255.0, ft_atoi(tmp[1]) / 255.0, ft_atoi(tmp[2]) / 255.0);
	ft_release_strs(tmp);
	data->light = light;
}

void	fill_camera_data(t_info_data *data)
{
	data->camera.viewprot_height = VIEWPORT_HEIGHT;
	data->camera.viewprot_width = VIEWPORT_HEIGHT * data->canvas.aspect_ratio;
	data->camera.focal_length = FOCAL_LENGTH;
	data->camera.horizontal = vec(data->camera.viewprot_width, 0, 0);
	data->camera.vertical = vec(0, data->camera.viewprot_height, 0);
	data->camera.lower_left_corner = vec_sub(vec_sub(vec_sub \
		(data->camera.coordinates, \
		vec_div(data->camera.horizontal, 2)), \
		vec_div(data->camera.vertical, 2)), \
		vec(0, 0, FOCAL_LENGTH));
}
