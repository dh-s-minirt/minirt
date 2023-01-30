/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:54:56 by daegulee          #+#    #+#             */
/*   Updated: 2023/01/30 17:52:20 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include <stdio.h>
#include "../math/math.h"

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
	rotate.m[1][0] = -sin(radian);
	rotate.m[1][1] = cos(radian);
	return (rotate);
}

t_mat4	_rotate_mat_(const double theta, char mode)
{
	if (mode == 'X' || mode == 'x')
		_rotate_x_(theta);
	if (mode == 'Y' || mode == 'y')
		_rotate_y_(theta);
	if (mode == 'Z' || mode == 'z')
		_rotate_z_(theta);
	else
	{
		printf("Please use correct rotate_mode.\n");
		exit(EXIT_FAILURE);
	}
}
