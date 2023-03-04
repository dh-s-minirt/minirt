/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:59:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/04 17:03:28 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	rotate_up_c_y(t_zip *zip, double theta);
void	rotate_up_nor_y(t_zip *zip, double theta);

void	rotate_up_y(t_zip *zip, double theta)
{
	rotate_up_c_y(zip, theta);
	rotate_up_nor_y(zip, theta);
}

void	rotate_up_c_y(t_zip *zip, double theta)
{
	if (zip->mdat->obj_type == PLANE)
		((t_plane *)(zip->mdat->object))->nor_vector = _rotate_vec_(theta, 'y', \
		((t_plane *)(zip->mdat->object))->nor_vector);
	else if (zip->mdat->obj_type == SPHERE)
		return ;
	else if (zip->mdat->obj_type == CONE)
	{
		((t_cone *)(zip->mdat->object))->nor_vector = _rotate_vec_(theta, 'y', \
		((t_cone *)(zip->mdat->object))->nor_vector);
		((t_cone *)(zip->mdat->object))->bot->nor_v = _rotate_vec_(theta, 'y', \
		((t_cone *)(zip->mdat->object))->bot->nor_v);
	}
	else if (zip->mdat->obj_type == DISK)
	{
		((t_disk *)(zip->mdat->object))->nor_v = _rotate_vec_(theta, 'y', \
		((t_disk *)(zip->mdat->object))->nor_v);
		if (((t_disk *)(zip->mdat->object))->parent_type == CONE)
			((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector = _rotate_vec_(theta, 'y', \
		((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector);
		else
			((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector = _rotate_vec_(theta, 'y', \
		((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector);
	}
	else if (zip->mdat->obj_type == CYLINDER)
	{
		((t_cylinder *)(zip->mdat->object))->nor_vector = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->nor_vector);
		if (((t_cylinder *)(zip->mdat->object))->bot == NULL)
			return ;
		((t_cylinder *)(zip->mdat->object))->bot->nor_v = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->bot->nor_v);
		((t_cylinder *)(zip->mdat->object))->top->nor_v = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->top->nor_v);
	}
	else
		return ;
}

void	rotate_up_nor_y(t_zip *zip, double theta)
{
	if (zip->mdat->obj_type == PLANE)
		((t_plane *)(zip->mdat->object))->nor_vector = _rotate_vec_(theta, 'y', \
		((t_plane *)(zip->mdat->object))->nor_vector);
	else if (zip->mdat->obj_type == SPHERE)
		return ;
	else if (zip->mdat->obj_type == CONE)
	{
		((t_cone *)(zip->mdat->object))->nor_vector = _rotate_vec_(theta, 'y', \
		((t_cone *)(zip->mdat->object))->nor_vector);
		((t_cone *)(zip->mdat->object))->bot->nor_v = _rotate_vec_(theta, 'y', \
		((t_cone *)(zip->mdat->object))->bot->nor_v);
	}
	else if (zip->mdat->obj_type == DISK)
	{
		((t_disk *)(zip->mdat->object))->nor_v = _rotate_vec_(theta, 'y', \
		((t_disk *)(zip->mdat->object))->nor_v);
		if (((t_disk *)(zip->mdat->object))->parent_type == CONE)
			((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector = _rotate_vec_(theta, 'y', \
		((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector);
		else
			((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector = _rotate_vec_(theta, 'y', \
		((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			nor_vector);
	}
	else if (zip->mdat->obj_type == CYLINDER)
	{
		((t_cylinder *)(zip->mdat->object))->nor_vector = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->nor_vector);
		if (((t_cylinder *)(zip->mdat->object))->bot == NULL)
			return ;
		((t_cylinder *)(zip->mdat->object))->bot->nor_v = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->bot->nor_v);
		((t_cylinder *)(zip->mdat->object))->top->nor_v = \
		_rotate_vec_(theta, 'y', \
		((t_cylinder *)(zip->mdat->object))->top->nor_v);
	}
	else
		return ;
}