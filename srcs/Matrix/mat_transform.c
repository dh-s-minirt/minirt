/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:56:57 by daegulee          #+#    #+#             */
/*   Updated: 2023/01/30 19:56:29 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include "../math/math.h"
// vector를 matrix에 곱함 -> 예 ) 카메라 자표계에 있는 점을
// 카메라 투 월드 행렬에 곱하면 월드 좌표계로 바뀜

t_vec	_mup_vec_mat(const t_mat4 a, t_arr_vec3	arr_vec)
{
	t_arr_vec3	vec3;
	int			row;
	int			col;
	int			cord;

	row = -1;
	col = -1;
	cord = -1;
	while (++cord < 3)
	{	
		vec3.v[cord] = 0;
		while (++row < 3)
			while (++col < 3)
				vec3.v[cord] += a.m[row][col] * arr_vec.v[col];
	}
	return (arr_vec3_2_vec(vec3));
}
