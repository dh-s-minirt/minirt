/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:54:56 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/02 21:56:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include <stdio.h>
#include "../math/math.h"
#include "../settings/setting.h"

static t_mat4	_rotate_x_(const double theta);
static t_mat4	_rotate_y_(const double theta);
static t_mat4	_rotate_z_(const double theta);

static t_mat4	_rotate_x_(const double theta)
{
	t_mat4			rotate;
	const double	radian = degrees_to_radians(theta);

	rotate = _init_mat_(I);
	rotate.m[1][1] = cos(radian);
	rotate.m[1][2] = sin(radian);
	rotate.m[2][1] = -sin(radian);
	rotate.m[2][2] = cos(radian);
	return (rotate);
}

static t_mat4	_rotate_y_(const double theta)
{
	t_mat4			rotate;
	const double	radian = degrees_to_radians(theta);

	rotate = _init_mat_(I);
	rotate.m[0][0] = cos(radian);
	rotate.m[0][2] = -sin(radian);
	rotate.m[2][0] = sin(radian);
	rotate.m[2][2] = cos(radian);
	return (rotate);
}

static t_mat4	_rotate_z_(const double theta)
{
	t_mat4			rotate;
	const double	radian = degrees_to_radians(theta);

	rotate = _init_mat_(I);
	rotate.m[0][0] = cos(radian);
	rotate.m[0][1] = -sin(radian);
	rotate.m[1][0] = sin(radian);
	rotate.m[1][1] = cos(radian);
	return (rotate);
}

t_mat4	_rotate_mat_(const double theta, char mode)
{
	t_mat4	rotate;

	if (mode == 'X' || mode == 'x')
		rotate = _rotate_x_(theta);
	else if (mode == 'Y' || mode == 'y')
		rotate = _rotate_y_(theta);
	else if (mode == 'Z' || mode == 'z')
		rotate = _rotate_z_(theta);
	else
	{
		printf("Please use correct rotate_mode.\n");
		exit(EXIT_FAILURE);
	}
	return (rotate);
}

t_vec	_rotate_vec_(const double theta, char mode, const t_vec source)
{
	const t_mat4	origin = _camera_to_world_(source);
	t_mat4			rotate;
	t_vec			local_v;

	if (mode == 'X' || mode == 'x')
		rotate = _rotate_x_(theta);
	else if (mode == 'Y' || mode == 'y')
		rotate = _rotate_y_(theta);
	else if (mode == 'Z' || mode == 'z')
		rotate = _rotate_z_(theta);
	else
	{
		printf("Please use correct rotate_mode.\n");
		exit(EXIT_FAILURE);
	}
	local_v = _mul_vec_mat(\
	_mul_mat_(origin, rotate), vec_2_arr_vec3(vec(0, 0, 1)));
	return (local_v);
}
