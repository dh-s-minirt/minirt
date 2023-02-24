/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:01 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/24 19:56:22 by daegulee         ###   ########.fr       */
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

double	modulo(double x)
{
	return (x - floor(x));
}

void	_uv_pattern_(t_hit_rec *cur_h_rec)
{
	const double	checker_width = 8.0;
	const double	checker_height = 8.0;
	const double	on_u = modulo(cur_h_rec->u * checker_width);
	const double	on_v = modulo(cur_h_rec->v * checker_height);

	if (((on_u < 0.5) + (on_v < 0.5)) % 2 == 0)
		cur_h_rec->albedo = vec(1, 1, 1);
	else
		cur_h_rec->albedo = copy_clamp(vec_mul(cur_h_rec->albedo, 255), 0, 1);
}

void	spherical_mapping(t_hit_rec *cur_h_rec)
{
	const double	theta = atan2(cur_h_rec->hit_normal.z, \
	cur_h_rec->hit_normal.x);
	const double	phi = asin(cur_h_rec->hit_normal.y);

	cur_h_rec->u = 0.5 - theta / (2 * PI);
	cur_h_rec->v = 0.5 - phi / PI;
}


static void	get_uv(t_hit_rec *cur_h_rec)
{
	spherical_mapping(cur_h_rec);
	_uv_pattern_(cur_h_rec);
}

t_color	_shade_uv(t_hit_rec hit_rec, t_info_data *data, t_ray r)
{
	t_color			phong;
	t_phong_propety	property;

	property.kd = 0.8;
	property.ks = 0.2;
	property.n = 20;
	get_uv(&hit_rec);
	phong = _shade_kphong(hit_rec, data, &property, r);
	return (phong);
}
