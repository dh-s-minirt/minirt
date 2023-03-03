/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:11:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 23:37:21 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "../color/color.h"

static void	color_hitrec_init(t_color *pixel_color, t_hit_rec *hit_rec)
{
	*pixel_color = vec(0, 0, 0);
	*hit_rec = _init_rec_();
}

t_color	ray_casting(t_ray r, t_info_data *data, int depth)
{
	t_color		pixel_color;
	t_hit_rec	hit_rec;

	if (depth > MAX_DEPTH)
		return (vec(0, 0, 0));
	color_hitrec_init(&pixel_color, &hit_rec);
	if (trace_hit(data->objects, &hit_rec, r))
	{
		if (hit_rec.material.m_type == PHONG)
			pixel_color = _shade_kphong(hit_rec, data, \
		(t_phong_propety *)(hit_rec.material.property), r);
		else if (hit_rec.material.m_type == REFLECT)
			pixel_color = _shade_reflect(hit_rec, data, depth, r);
		else if (hit_rec.material.m_type == FRESNEL)
			pixel_color = _shade_refract(hit_rec, data, r, (t_fres_data) \
			{((t_fres_property *)hit_rec.material.property)->ior, depth});
		else if (hit_rec.material.m_type == UV)
			pixel_color = _shade_uv(hit_rec, data, r);
		else if (hit_rec.material.m_type == SPECIAL)
			pixel_color = _shade_special(hit_rec, data, r);
		else
			pixel_color = vec(0, 0, 0);
	}
	return (pixel_color);
}

void	put_color(t_color pixel_color, int row, int col, t_mlx_data *data)
{
	int		color;
	t_color	clmaped_pixel;

	clmaped_pixel = copy_clamp(pixel_color, 0, 1.0);
	color = write_color(0, clmaped_pixel);
	my_mlx_pixel_put(data, col + 400, row + 200, color);
}

void	*render(void *source_zip)
{
	const t_zip	*zip = (t_zip *)source_zip;
	int			i;
	int			j;
	double		xy[2];
	t_ray		r;

	j = zip->start_row - 1;
	while (++j < zip->start_row + zip->set.screen_height / THREAD_N)
	{
		i = -1;
		while (++i < zip->set.screen_width)
		{
			xy[X] = (2 * (i + 0.5) / (double)(zip->set.screen_width) - 1) * \
			zip->set.scale;
			xy[Y] = (1 - 2 * (j + 0.5) / (double)(zip->set.screen_height)) \
			* zip->set.aspect_ratio * zip->set.scale;
			r.dir = vec_unit(_mul_vec_mat(zip->set.camera_to_world, \
			vec_2_arr_vec3(vec(xy[X], xy[Y], -1))));
			r.origin = vec_copy(zip->set.camera.center);
			put_color(ray_casting(r, zip->data, 0), j, i, &(zip->mlx->img));
		}
	}
	printf("%d thread_finish :\n", zip->start_row * THREAD_N / \
	zip->set.screen_height);
	return (NULL);
}