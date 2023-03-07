/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:36:48 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/07 14:39:46 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	object_move(t_zip *zip, int keycode)
{
	long double	e;

	e = zip->set.scale / SCREEN_HEIGHT * 1000;
	if (zip->mdat->choice_obj == FALSE)
		return ;
	if (zip->mdat->obj_type == DISK)
	{
		zip->mdat->obj_type = ((t_disk *)(zip->mdat->object))->parent_type;
		zip->mdat->object = ((t_disk *)(zip->mdat->object))->parent;
		object_move(zip, keycode);
		return ;
	}
	if (keycode == KEY_A)
		update_center(zip, 'x', e);
	else if (keycode == KEY_Q)
		update_center(zip, 'x', -e);
	else if (keycode == KEY_W)
		update_center(zip, 'y', e);
	else if (keycode == KEY_S)
		update_center(zip, 'y', -e);
	else if (keycode == KEY_E)
		update_center(zip, 'z', e);
	else if (keycode == KEY_D)
		update_center(zip, 'z', -e);
	start_draw(zip);
}

void	camera_move(t_zip *zip, int keycode)
{
	long double	e;

	e = zip->set.scale / SCREEN_HEIGHT * 1000;
	if (keycode == KEY_A)
		zip->set.camera.center.x += e;
	else if (keycode == KEY_Q)
		zip->set.camera.center.x -= e;
	else if (keycode == KEY_W)
		zip->set.camera.center.y += e;
	else if (keycode == KEY_S)
		zip->set.camera.center.y -= e;
	else if (keycode == KEY_E)
		zip->set.camera.center.z += e;
	else if (keycode == KEY_D)
		zip->set.camera.center.z -= e;
}

void	zoom(t_zip *zip, int keycode)
{
	if (zip->mdat->mode == CMODE)
	{
		if (keycode == KEY_MINUS)
		{
			zip->set.fov += 10;
			zip->set.fov = clamp(zip->set.fov, 0, 179);
			zip->set.scale = tan(degrees_to_radians(zip->set.fov) * 0.5);
		}
		else if (keycode == KEY_PLUS)
		{
			zip->set.fov -= 10;
			zip->set.fov = clamp(zip->set.fov, 0, 179);
			zip->set.scale = tan(degrees_to_radians(zip->set.fov) * 0.5);
		}
		start_draw(zip);
	}
}

void	move(t_zip *zip, int keycode)
{
	if (zip->mdat->mode == CMODE)
		camera_move(zip, keycode);
	else
		object_move(zip, keycode);
	start_draw(zip);
}

int	my_exit(void *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}
