/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:30:00 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/09 23:34:30 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec(double x, double y, double z)
{
	t_vec	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

double	length_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_length(t_vec vec)
{
	return (sqrt(length_squared(vec)));
}

t_vec	vec_product(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}

t_vec	v_reflect(t_vec i, t_vec n)
{
	return (vec_sub(i, vec_mul(n, 2 * vec_dot(i, n))));
}
