/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:30:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/09 23:43:27 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit_record/hit_record.h"

typedef struct s_light_info
{
	t_vec	dir;
	t_vec	intensity;
}	t_light_info;

t_light_info	get_light_info(t_light_node *light, t_hit_rec hit_rec)
{
	t_light_info	cur_info;
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

t_color	_shade_kphong(t_hit_rec hit_rec, t_info_data *data, \
t_phong_propety *property)
{
	t_color			diffuse;
	t_color			specular;
	t_light_node	*cur_light;
	t_light_info	cur_l_info;
	t_bool			is_shadow;

	diffuse = vec(0, 0, 0);
	specular = vec(0, 0, 0);
	cur_light = data->lights;
	while (cur_light)
	{
		cur_l_info = get_light_info(cur_light, hit_rec);
		is_shadow = check_shadow(data->objects, &hit_rec, \
		vec_mul((cur_l_info.dir), -1));
		diffuse = vec_add(diffuse, \
		vec_mul(vec_product(hit_rec.albedo, cur_l_info.intensity), \
		!is_shadow * fmax_d(0, vec_dot(hit_rec.hit_normal, \
		vec_mul(cur_l_info.dir, -1)))));
		specular = vec_add(specular, \
		vec_mul(vec_mul(cur_l_info.intensity, \
		pow(fmax_d(0, vec_dot(vec_mul(cur_l_info.dir, -1), \
		hit_rec.hit_normal)), property->n)), !is_shadow));
	}
	return (vec_add(vec_mul(diffuse, property->kd), \
vec_mul(specular, property->ks)));
}
