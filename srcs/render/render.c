/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:11:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/18 15:29:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "../color/color.h"

void	init_property(t_hit_rec *hit_rec)
{
	t_phong_propety	*property;

	property = ft_malloc(sizeof(t_phong_propety));
	if (hit_rec->obj_type != PLANE)
	{
		property->kd = 0.8;
		property->ks = 0.2;
		property->n = 20;
	}
	else
		property->kd = 1;
	hit_rec->property = (void *)property;
}

t_color	ray_casting(t_ray r, t_info_data *data, int depth, t_settings set)
{
	t_color		pixel_color;
	t_hit_rec	hit_rec;

	if (depth > set.max_depth)
		return (set.dark);
	pixel_color = vec(0, 0, 0);
	hit_rec = _init_rec_();
	if (trace_hit(data->objects, &hit_rec, r))
	{
		init_property(&hit_rec);
		// printf("albedo r %lf: g %lf: b %lf:\n", \
		// hit_rec.albedo.x, hit_rec.albedo.y, hit_rec.albedo.z);
		// if (hit_rec.material == Kdiffuse)
		// 	_shade_diffuse();
		// else if (hit_rec.material == Kphong)
		pixel_color = _shade_kphong(hit_rec, data, \
		(t_phong_propety *)hit_rec.property, r);
		// if (pixel_color.x || pixel_color.y || pixel_color.z)
		// 	printf("pixel r %lf: g %lf: b %lf:\n", \
		// pixel_color.x, pixel_color.y, pixel_color.z);
		// // // else
		// 	_shade_kfresnel();
		free(hit_rec.property);
	}
	return (pixel_color);
}

void	put_color(t_color pixel_color, int row, int col, t_mlx_data *data)
{
	int		color;
	t_color	clmaped_pixel;

	// printf("color  r: %lf g : %lf b : %lf\n", pixel_color.x, pixel_color.y, pixel_color.z);
	clmaped_pixel = copy_clamp(pixel_color, 0, 1.0);
	color = write_color(0, clmaped_pixel);
	// printf("color  r: %d g : %d b : %d\n", get_r(color), get_g(color),get_b(color));
	my_mlx_pixel_put(data, col, row, color);
}

void	render(t_settings set, t_info_data	*data, t_my_mlx *mlx)
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
		printf("\rScanlines remaining: %d \n", set.screen_height-j-1);
		while (++i < set.screen_width)
		{
			x = (2 * (i + 0.5) / (double)(set.screen_width) - 1) * set.scale;
			y = (1 - 2 * (j + 0.5) / (double)(set.screen_height)) * set.aspect_ratio \
			* set.scale;
			r.dir = vec_unit(_mul_vec_mat(set.camera_to_world, \
			vec_2_arr_vec3(vec(x, y, -1))));
			r.origin = vec_copy(data->camera.center);
			put_color(ray_casting(r, data, 0, set), j, i, &(mlx->img));
		}
	}
}
