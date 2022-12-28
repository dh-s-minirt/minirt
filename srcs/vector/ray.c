/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:21:39 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 10:52:47 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
원점 좌표에서  t크기만큼 dir 방향으로 뻗어나가는 ray 벡터의 계산
*/
t_vec	ray_at(t_ray *ray, double t)
{
	t_vec	out;

	out.x = ray->origin.x + ray->dir.x * t;
	out.y = ray->origin.y + ray->dir.y * t;
	out.z = ray->origin.z + ray->dir.z * t;
	return (out);
}
