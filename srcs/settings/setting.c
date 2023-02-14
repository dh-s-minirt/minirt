/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:27:45 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 16:13:22 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./setting.h"
#include <stdio.h>
t_mat4	_camera_to_world_(t_camera	camera)
{
	const t_vec	forward = vec_unit(vec_sub(camera.center, vec(0, 0, 0)));
	const t_vec	right = vec_unit(vec_cross(vec(0, 1, 0), forward));
	const t_vec	up = vec_unit(vec_cross(forward, right));
	t_mat4		camera_to_world;

	camera_to_world = _make_mat_with_vec(right, up, forward);
	return (camera_to_world);
}

t_settings	_init_setting_(t_info_data data)
{
	t_settings	set;

	set.bias = 0.001;
	set.max_depth = 5;
	set.camera_to_world = _camera_to_world_(data.camera);
	set.screen_height = SCREEN_HEIGHT;
	set.screen_width = SCREEN_WIDTH;
	set.aspect_ratio = (double)set.screen_height / (double)set.screen_width;
	set.fov = data.camera.fov;
	set.dark = vec(0, 0, 0);
	set.scale = tan(degrees_to_radians(set.fov * 0.5));
	return (set);
}
