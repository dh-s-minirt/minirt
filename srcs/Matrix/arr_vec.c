/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:49:03 by daegulee          #+#    #+#             */
/*   Updated: 2023/01/30 19:53:19 by daegulee         ###   ########.fr       */
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
