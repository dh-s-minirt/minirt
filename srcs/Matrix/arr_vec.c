/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:49:03 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 15:02:54 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../math/math.h"
#include "./matrix.h"

t_arr_vec3	vec_2_arr_vec3(t_vec vec)
{
	t_arr_vec3	arr_vec;

	arr_vec.v[0] = vec.x;
	arr_vec.v[1] = vec.y;
	arr_vec.v[2] = vec.z;
	return (arr_vec);
}

t_vec	arr_vec3_2_vec(t_arr_vec3 vec3)
{
	t_vec	vec;

	vec.x = vec3.v[0];
	vec.y = vec3.v[1];
	vec.z = vec3.v[2];
	return (vec);
}

t_mat4	_make_mat_with_vec(const t_vec	x_cord, const t_vec	y_cord, \
const t_vec	z_cord)
{
	t_mat4	tmp;

	tmp = _init_mat_(I);
	tmp.m[0][0] = x_cord.x;
	tmp.m[0][1] = x_cord.y;
	tmp.m[0][2] = x_cord.z;
	tmp.m[1][0] = y_cord.x;
	tmp.m[1][1] = y_cord.y;
	tmp.m[1][2] = y_cord.z;
	tmp.m[2][0] = z_cord.x;
	tmp.m[2][1] = z_cord.y;
	tmp.m[2][2] = z_cord.z;
	return (tmp);
}
