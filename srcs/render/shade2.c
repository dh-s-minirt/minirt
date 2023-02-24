/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:01 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/24 14:23:09 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	_shade_reflect(t_hit_rec hit_rec, t_info_data *data, int depth, \
t_ray ray)
{
	const t_vec	reflect = vec_unit(v_reflect(ray.dir, hit_rec.hit_normal));
	t_ray		reflect_ray;

	reflect_ray.dir = vec_copy(reflect);
	reflect_ray.origin = vec_add(hit_rec.contact_point, \
	vec_mul(hit_rec.hit_normal, BIAS));
	return (ray_casting(reflect_ray, data, depth + 1));
}

double	modulo(const double x)
{
	return (x - floor(x));
}

t_color	_shade_uv(t_hit_rec hit_rec, t_info_data *data, t_ray r)
{
	const double	scale_u = 1.0;
	const double	scale_v = 1.0;
	double			pattern;
	t_color			phong;
	t_phong_propety	property;

	pattern = (modulo(uv[1] * scale_v) < 0.5) ^ \
	(modulo(uv[0] * scale_u) < 0.5);
	property.kd = 0.8;
	property.ks = 0.2;
	property.n = 20;
	phong = _shade_kphong(hit_rec, data, &property, r);
	printf("%lf\n", pattern);
	// return (vec_mul(phong, pattern));
	pattern = 0;
	return (phong);
}