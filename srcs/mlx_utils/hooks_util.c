/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 01:34:05 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 15:57:42 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	change_mode(t_zip *zip)
{
	if (zip->mdat->mode == CMODE)
		zip->mdat->mode = OMODE;
	else
		zip->mdat->mode = CMODE;
	start_draw(zip);
}

void	change_select(t_zip *zip)
{
	if (zip->mdat->choice_obj == TRUE && \
	zip->mdat->mode == OMODE)
	{
		zip->mdat->choice_obj = FALSE;
		zip->mdat->object = NULL;
		start_draw(zip);
	}
}

void	object_picking(int x, int y, t_zip *zip)
{
	t_ray		obj_ray;
	double		world_x;
	double		world_y;
	t_hit_rec	hit_rec;

	hit_rec = _init_rec_();
	world_x = (2 * (x - TITLE_WIDTH + 0.5) \
	/ (double)(zip->set.screen_width) - 1) * \
	zip->set.scale;
	world_y = (1 - 2 * (y - TITLE_HIGHT \
	+ 0.5) / (double)(zip->set.screen_height)) \
	* zip->set.aspect_ratio * zip->set.scale;
	obj_ray.dir = vec_unit(_mul_vec_mat(zip->set.camera_to_world, \
		vec_2_arr_vec3(vec(world_x, world_y, -1))));
	obj_ray.origin = vec_copy(zip->set.camera.center);
	if (trace_hit(zip->data->objects, &hit_rec, obj_ray))
	{
		zip->mdat->object = hit_rec.object;
		zip->mdat->choice_obj = TRUE;
		zip->mdat->obj_type = hit_rec.obj_type;
		printf("pick : %d\n", zip->mdat->obj_type);
		start_draw(zip);
	}
}
