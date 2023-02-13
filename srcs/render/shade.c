/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:30:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/13 23:44:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_lt_info	get_lt_info(t_light_node *light, t_hit_rec hit_rec)
{
	t_lt_info		cur_info;
	t_am_light		*dist_light;
	t_light			*point_light;

	if (light->type == AM_LIGHT)
	{
		dist_light = (t_am_light *)light->data;
		cur_info.dir = vec(0, -1, 0);
		cur_info.intensity = dist_light->color;
	}
	else
	{
		point_light = (t_light *)light->data;
		cur_info.dir = vec_sub(hit_rec.contact_point, point_light->center);
		cur_info.intensity = vec_div(point_light->color, \
		(4 * PI * length_squared(cur_info.dir)));
		cur_info.dir = vec_unit(cur_info.dir);
	}
	return (cur_info);
}

t_bool	check_shadow(t_node	*objects, t_hit_rec	*hit_rec, t_vec dir)
{
	t_ray			shadow_ray;
	t_hit_rec		tmp;

	shadow_ray.origin = vec_add(hit_rec->contact_point, \
	vec_mul(hit_rec->hit_normal, BIAS));
	shadow_ray.dir = dir;
	return (trace_hit(objects, &tmp, shadow_ray));
}

static t_color	_get_specular_(t_lt_info cur_l_info, \
t_hit_rec	hit_rec, t_phong_propety *property, t_ray ray)
{
	t_vec	reflect;
	t_color	specular;
	t_vec	v;
	double	mul;

	reflect = v_reflect(cur_l_info.dir, hit_rec.hit_normal);
	v = vec_mul(ray.dir, -1);
	mul = pow(fmax_d(0, vec_dot(reflect, v)), property->n);
	specular = vec_mul(cur_l_info.intensity, mul);
	return (specular);
}

static t_color	_get_diffuse_(t_lt_info cur_l_info, t_hit_rec hit_rec)
{
	t_color	max_diffuse_color;
	double	coefficient;

	max_diffuse_color = vec_product(hit_rec.albedo, cur_l_info.intensity);
	coefficient = fmax_d(0, vec_dot(hit_rec.hit_normal, \
	vec_mul(cur_l_info.dir, -1)));
	return (vec_mul(max_diffuse_color, coefficient));
}

t_color	_shade_kphong(t_hit_rec hit_rec, t_info_data *data, \
t_phong_propety *property, t_ray ray)
{
	t_color			diffuse;
	t_color			specular;
	t_light_node	*cur_light;
	t_lt_info		cur_l_info;
	t_bool			is_shadow;

	diffuse = vec(0, 0, 0);
	specular = vec(0, 0, 0);
	cur_light = data->lights;
	while (cur_light)
	{
		cur_l_info = get_lt_info(cur_light, hit_rec);
		is_shadow = check_shadow(data->objects, &hit_rec, \
		vec_mul((cur_l_info.dir), -1));
		diffuse = vec_add(diffuse, \
		vec_mul(_get_diffuse_(cur_l_info, hit_rec), \
		!is_shadow));
		specular = vec_add(specular, \
		vec_mul(_get_specular_(cur_l_info, hit_rec, property, ray), \
		!is_shadow));
	}
	return (vec_add(vec_mul(diffuse, property->kd), \
vec_mul(specular, property->ks)));
}
