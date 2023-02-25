/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:56:57 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/25 22:53:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include "../math/math.h"
#include <stdio.h>
// vector를 matrix에 곱함 -> 예 ) 카메라 자표계에 있는 점을
// 카메라 투 월드 행렬에 곱하면 월드 좌표계로 바뀜

t_vec	_mul_vec_mat(const t_mat4 a, t_arr_vec3	arr_vec)
{
	t_arr_vec3	vec3;
	int			row;
	int			col;
	int			cord;

	cord = -1;
	while (++cord < 3)
	{	
		row = cord;
		vec3.v[cord] = 0;
		col = -1;
		while (++col < 3)
			vec3.v[cord] += a.m[row][col] * arr_vec.v[col];
	}
	// print_mat(a);
	// printf("x : %lf y : %lf z %lf \n", arr_vec.v[0], arr_vec.v[1],arr_vec.v[2]);
	// printf("x : %lf y : %lf z %lf \n", vec3.v[0], vec3.v[1],vec3.v[2]);
	return (arr_vec3_2_vec(vec3));
}

t_mat4	_normal_cord_(t_vec	normal)
{
	const t_vec	forward = vec_unit(normal);
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

t_vec	get_x_cord(t_mat4 cord)
{
	t_vec	tmp;

	tmp.x = cord.m[0][0];
	tmp.y = cord.m[0][1];
	tmp.z = cord.m[0][2];
	return (tmp);
}

t_vec	get_y_cord(t_mat4 cord)
{
	t_vec	tmp;

	tmp.x = cord.m[1][0];
	tmp.y = cord.m[1][1];
	tmp.z = cord.m[1][2];
	return (tmp);
}

t_vec	get_z_cord(t_mat4 cord)
{
	t_vec	tmp;

	tmp.x = cord.m[2][0];
	tmp.y = cord.m[2][1];
	tmp.z = cord.m[2][2];
	return (tmp);
}
