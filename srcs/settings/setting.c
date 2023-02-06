/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:27:45 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 08:20:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./setting.h"
#include "../mini_rt.h"

t_mat4	_camera_to_world_(t_camera	camera)
{
	const t_vec	forward = vec_unit(vec_sub(camera.center, vec(0, 0, 0)));
	const t_vec	right = vec_cross(vec(0, 1, 0), forward);
	const t_vec	up = vec_cross(forward, right);
	t_mat4		camera_to_world;

	camera_to_world = _make_mat_with_vec(forward, right, up);
	return (camera_to_world);
}

t_settings	_init_setting_(t_info_data data)
{
	t_settings	set;

	set.bias = 0.001;
	set.max_depth = 5;
	set.camera_to_world = _camera_to_world_(data.camera);
	set.screen_height = SCREEN_HEIGHT;
	set.screen_width = SCREEN_HEIGHT;
	set.aspect_ratio = set.screen_height / set.screen_height;
	set.fov = data.camera.fov;
	set.scale = tan(degrees_to_radians(set.fov * 0.5));
	return (set);
}
