/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:21:39 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/02 10:46:53 by hyunkyu          ###   ########.fr       */
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

t_ray	ray(t_vec orig, t_vec dir)
{
    t_ray ray;

    ray.origin = orig;
    ray.dir = vec_unit(dir);
    return (ray);
}

t_ray ray_primary(t_camera cam, double u, double v)
{
    t_ray   ray;

    ray.origin = cam.coordinates;
    ray.dir = vec_unit(vec_sub(vec_add(vec_add(cam.lower_left_corner, \
		vec_mul(cam.horizontal, u)), vec_mul(cam.vertical, v)), cam.coordinates));
    return (ray);
}
