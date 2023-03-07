/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:10:33 by idaegyu           #+#    #+#             */
/*   Updated: 2023/03/07 11:57:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	camera_rotate(t_zip *zip, int keycode)
{	
	if (keycode == KEY_ROT_XM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'x'));
	else if (keycode == KEY_ROT_XP)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'x'));
	else if (keycode == KEY_ROT_YM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'y'));
	else if (keycode == KEY_ROT_YP)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'y'));
	else if (keycode == KEY_ROT_ZM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'z'));
	else if (keycode == KEY_ROT_ZP){
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'z'));
	}
	else
		return ;
	start_draw(zip);
}