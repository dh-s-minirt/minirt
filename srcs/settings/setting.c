/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:27:45 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/02 21:00:18 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./setting.h"
#include <stdio.h>

t_mat4	_camera_to_world_(t_vec	normal)
{
	const t_vec	forward = vec_unit(vec_product(normal, \
	vec(1, 1, -1)));
	t_vec		up;
	t_vec		right;
	t_mat4		camera_to_world;

	if (forward.y == 1.0 || forward.y == -1.0)
		right = vec(forward.y, 0, 0);
	else
		right = vec_unit(vec_cross(vec(0, 1, 0), forward));
	up = vec_unit(vec_cross(forward, right));
	camera_to_world = _make_mat_with_vec(right, up, forward);
	return (camera_to_world);
}

t_settings	_init_setting_(t_camera camera)
{
	t_settings			set;

	set.camera = camera;
	set.bias = 0.001;
	set.camera_to_world = _camera_to_world_(camera.nor_vector);
	set.screen_height = SCREEN_HEIGHT;
	set.screen_width = SCREEN_WIDTH;
	set.aspect_ratio = (double)set.screen_height / (double)set.screen_width;
	set.fov = clamp(camera.fov, 1, 179);
	set.scale = tan(degrees_to_radians(set.fov * 0.5));
	return (set);
}
