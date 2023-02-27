/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:01 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/27 15:33:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../parsing_ppm/parsing_ppm.h"

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

t_color	_shade_uv(t_hit_rec hit_rec, t_info_data *data, t_ray r)
{
	t_color			phong;
	t_phong_propety	property;

	property.kd = 0.8;
	property.ks = 0.2;
	property.n = 20;
	get_uv(&hit_rec);
	_check_pattern_(&hit_rec, 5.0);
	phong = _shade_kphong(hit_rec, data, &property, r);
	return (phong);
}

void	_get_special(t_hit_rec *hit_rec, t_ppm *ppm)
{
	double	x;
	double	y;

	x = hit_rec->u * (ppm->width - 1);
	y = hit_rec->v * (ppm->height - 1);
	hit_rec->albedo = (ppm->map)[(int)round(y) * ppm->height + (int)round(x)];
}

t_color	_shade_special(t_hit_rec hit_rec, t_info_data *data, t_ray r)
{
	const t_special_property	*special = \
	(t_special_property *)hit_rec.material.property;
	static t_ppm				*ppm;
	char						*str;
	t_phong_propety				property;

	if (special->special_type == S1)
		str = "./ppm/earth.ppm";
	else if (special->special_type == S2)
		str = "./ppm/moon.ppm";
	else
		str = "./ppm/s1.ppm";
	property.kd = 1.0;
	property.ks = 0.2;
	property.n = 20;
	printf("%s\n", str);
	if (ppm == NULL)
		ppm = parse_ppm(str);
	get_uv(&hit_rec);
	_get_special(&hit_rec, ppm);
	return (_shade_kphong(hit_rec, data, &property, r));
}
