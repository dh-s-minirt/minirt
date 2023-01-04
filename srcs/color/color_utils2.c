/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:41 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/01/03 14:25:35 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_sub(v, vec_mul(n, 2 * vec_dot(v, n))));
}

t_color	ray_color(t_info_data *data)
{
}

t_color	point_light_get(t_info_data *data)
{
	struct s_dummy_color	dummy;

	// 교점에서 광원을 향하는 백터
	// dummy.light_dir = vec_unit(vec_sub(data->light.coordinates, data->hit_record->p));
	// dummy.kd = fmax(vec_dot(data->hit_record->normal, dummy.light_dir), 0.0);
	dummy.diffuse = vec_mul(data->light.color, dummy.kd);
	dummy.view_dir = vec_unit(vec_mul(data->ray.dir, -1));
	// dummy.reflect_dir = reflect(vec_mul(dummy.light_dir, -1), data->hit_record->normal);
	dummy.ksn = 64;
	dummy.ks = 0.5;
	dummy.spec = powf(fmax(vec_dot(dummy.view_dir, dummy.reflect_dir), \
		0.0), dummy.ksn);
	dummy.specular = vec_mul((vec_mul(data->light.color, dummy.ks)), \
		dummy.spec);
	dummy.brightness = data->light.ratio * LUMEN;
	return (vec_mul(vec_add(vec_add(dummy.diffuse, dummy.specular), \
		data->am_light), dummy.brightness));
}

t_color	phong_lighting(t_info_data *data)
{
	t_color	light_color;

	light_color = vec(0, 0, 0);
	light_color = vec_add(light_color, point_light_get(data));
	// hit_record에 저장된 오브젝트의 반사율과 곱해준다. 
	//return (vec_less(vec_mul(light_color, ), vec(1, 1, 1)))
	return (light_color);
}