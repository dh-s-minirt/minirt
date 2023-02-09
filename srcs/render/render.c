/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:11:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/09 23:12:40 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit_record/hit_record.h"

void	init_property(t_hit_rec *hit_rec)
{
	t_phong_propety	*property;

	property = ft_malloc(sizeof(t_phong_propety));
	property->kd = 0.9;
	property->ks = 0.1;
	property->n = 50;
	hit_rec->property = (void *)property;
}

t_color	ray_casting(t_ray r, t_info_data *data, int depth, t_settings set)
{
	t_color		pixel_color;
	t_hit_rec	hit_rec;

	if (depth > set.max_depth)
		return (set.dark);
	pixel_color = vec(0, 0, 0);
	if (trace_hit(data->objects, &hit_rec, r))
	{
		init_property(&hit_rec);
		// if (hit_rec.material == Kdiffuse)
		// 	_shade_diffuse();
		// else if (hit_rec.material == Kphong)
			_shade_kphong(hit_rec, data, (t_phong_propety *)hit_rec.property);
		// else
		// 	_shade_kfresnel();
		free(hit_rec.property);
	}
	return (pixel_color);
}

void	render(t_settings set, t_info_data	*data)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_ray	r;

	j = -1;
	while (++j < set.screen_height)
	{
		i = -1;
		while (++i < set.screen_width)
		{
			x = (2 * (i + 0.5) / set.screen_width - 1) * set.scale;
			y = (1 - 2 * (j + 0.5) / (set.screen_height)) \
			* set.scale * set.aspect_ratio;
			r.dir = vec_unit(_mul_vec_mat(set.camera_to_world, \
			vec_2_arr_vec3(vec(x, y, -1))));
			r.origin = _mul_vec_mat(set.camera_to_world, \
			vec_2_arr_vec3(vec(0, 0, 0)));
			ray_casting(r, data, 0, set);
//			write_color();
		}
	}
}