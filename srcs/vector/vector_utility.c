/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:48:46 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/29 11:32:39 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.y * v2.z + v1.z * v2.y;
	out.y = v1.z * v2.x + v1.x * v2.z;
	out.z = v1.x * v2.y + v1.y * v2.x;
	return (out);
}

t_vec	vec_unit(t_vec v)
{
	double	len;

	len = vec_length(&v);
	return (vec(v.x / len, v.y / len, v.z / len));
}
