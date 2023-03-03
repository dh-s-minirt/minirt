/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:56:57 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 16:13:44 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include "../math/math.h"
#include <stdio.h>

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
	return (arr_vec3_2_vec(vec3));
}
