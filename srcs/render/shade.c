/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:30:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 16:41:18 by daegulee         ###   ########.fr       */
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
		cur_info.dist = INFINITY;
	}
	else
	{
		point_light = (t_light *)light->data;
		cur_info.dir = vec_sub(hit_rec.contact_point, point_light->center);
		cur_info.dist = vec_length(cur_info.dir);
		cur_info.intensity = copy_vec_clamp(vec_mul(point_light->color, \
		pow(((double)DEFAULT_R / cur_info.dist), 2)), vec(0, 0, 0), \
		point_light->color);
		cur_info.dir = vec_unit(cur_info.dir);
	}
	return (cur_info);
}

t_bool	check_shadow(t_node	*objects, t_hit_rec	*hit_rec, t_vec dir, \
t_lt_info cur_l_info)
{
	t_ray			shadow_ray;
	t_hit_rec		tmp;
	t_bool			shadow;

	shadow_ray.origin = vec_add(hit_rec->contact_point, \
	vec_mul(hit_rec->hit_normal, BIAS));
	shadow_ray.dir = dir;
	tmp = _init_rec_();
	shadow = trace_hit(objects, &tmp, shadow_ray);
	if (shadow && tmp.t_near + BIAS < cur_l_info.dist && \
	tmp.material.m_type != FRESNEL)
		return (TRUE);
	return (FALSE);
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
	mul = pow(fmax_d(BIAS, vec_dot(reflect, v)), property->n);
	specular = vec_mul(cur_l_info.intensity, mul);
	return (specular);
}

static t_color	_get_diffuse_(t_lt_info cur_l_info, t_hit_rec hit_rec)
{
	t_color	max_diffuse_color;
	double	coefficient;

	max_diffuse_color = vec_product(hit_rec.albedo, cur_l_info.intensity);
	coefficient = fmax_d(BIAS, vec_dot(hit_rec.hit_normal, \
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
		vec_mul((cur_l_info.dir), -1), cur_l_info);
		diffuse = vec_add(diffuse, \
		vec_mul(_get_diffuse_(cur_l_info, hit_rec), !is_shadow));
		if (property->kd != 1.0)
			specular = vec_add(specular, \
		vec_mul(_get_specular_(cur_l_info, hit_rec, \
		property, ray), !is_shadow));
		cur_light = cur_light->next;
	}
	return (vec_add(vec_mul(diffuse, \
	property->kd), \
	vec_mul(specular, property->ks)));
}
