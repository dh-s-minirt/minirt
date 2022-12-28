/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:39:28 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 18:07:59 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
	return (out);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	return (out);
}

t_vec	vec_mul(t_vec v1, double t)
{
	t_vec	out;

	out.x = v1.x * t;
	out.y = v1.y * t;
	out.z = v1.z * t;
	return (out);
}

t_vec	vec_div(t_vec v1, double t)
{
	t_vec	out;

	out.x = v1.x / t;
	out.y = v1.y / t;
	out.z = v1.z / t;
	return (out);
}
