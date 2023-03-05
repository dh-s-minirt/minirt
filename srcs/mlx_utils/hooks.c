/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/06 02:49:24 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	start_draw(t_zip *zip)
{
	multi_thread(zip->set, (zip->data), zip->mlx);
	draw_frame(&zip->mlx->img);
	draw_topbar(zip->mlx, *(zip->mdat));
	mlx_put_image_to_window(zip->mlx->mlx, \
	zip->mlx->mlx_win, zip->mlx->img.img, 0, 0);
}

void	update_center(t_zip *zip, char mode, long double e)
{
	if (mode == 'x')
		update_center_x(zip, e);
	if (mode == 'y')
		update_center_y(zip, e);
	if (mode == 'z')
		update_center_z(zip, e);
}

// void	object_move(t_zip *zip, int keycode)
// {
// 	long double	e;

// 	e = zip->set.scale / SCREEN_HEIGHT * 1000;
// 	if (zip->mdat->choice_obj == FALSE)
// 		return ;
// 	if (keycode == KEY_A)
// 		update_center(zip, 'x', e);
// 	else if (keycode == KEY_Q)
// 		update_center(zip, 'x', -e);
// 	else if (keycode == KEY_W)
// 	{
// 		printf("w\n");
// 		update_center(zip, 'y', e);
// 	}
// 	else if (keycode == KEY_S)
// 		update_center(zip, 'y', -e);
// 	else if (keycode == KEY_E)
// 		update_center(zip, 'z', e);
// 	else if (keycode == KEY_D)
// 		update_center(zip, 'z', -e);
// 	else if (keycode == KEY_ROT_XM)
// 		obj_update_r_center(zip, 'x', -15);
// 	else if (keycode == KEY_ROT_XP)
// 		obj_update_r_center(zip, 'x', 15);
// 	else if (keycode == KEY_ROT_YM)
// 		obj_update_r_center(zip, 'y', -15);
// 	else if (keycode == KEY_ROT_YP)
// 		obj_update_r_center(zip, 'y', 15);
// 	else if (keycode == KEY_ROT_ZM)
// 		obj_update_r_center(zip, 'z', -15);
// 	else if (keycode == KEY_ROT_ZP){
// 		obj_update_r_center(zip, 'z', 15);
// 	}
// 	start_draw(zip);
// }

// void	camera_move(t_zip *zip, int keycode)
// {
// 	long double	e;

// 	e = zip->set.scale / SCREEN_HEIGHT * 1000;
// 	if (keycode == KEY_A)
// 		zip->set.camera.center.x += e;
// 	else if (keycode == KEY_Q)
// 		zip->set.camera.center.x -= e;
// 	else if (keycode == KEY_W)
// 		zip->set.camera.center.y += e;
// 	else if (keycode == KEY_S)
// 		zip->set.camera.center.y -= e;
// 	else if (keycode == KEY_E)
// 		zip->set.camera.center.z += e;
// 	else if (keycode == KEY_D)
// 		zip->set.camera.center.z -= e;
// 	else if (keycode == KEY_MINUS)
// 		zip->set.scale = tan(degrees_to_radians(clamp\
// 		((zip->set.fov += 10), 1, 179) * 0.5));
// 	else if (keycode == KEY_PLUS)
// 		zip->set.scale = tan(degrees_to_radians(clamp\
// 		((zip->set.fov -= 10), 1, 179) * 0.5));
// 	else if (keycode == KEY_ROT_XM)
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(-20, 'x'));
// 	else if (keycode == KEY_ROT_XP)
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(20, 'x'));
// 	else if (keycode == KEY_ROT_YM)
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(-20, 'y'));
// 	else if (keycode == KEY_ROT_YP)
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(20, 'y'));
// 	else if (keycode == KEY_ROT_ZM)
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(-20, 'z'));
// 	else if (keycode == KEY_ROT_ZP){
// 		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
// 		_rotate_mat_(20, 'z'));
// 	}
// 	else 
// 		return ;
// 	start_draw(zip);
// }

// void	move(t_zip *zip, int keycode)
// {
// 	if (zip->mdat->mode == CMODE)
// 		camera_move(zip, keycode);
// 	else
// 		object_move(zip, keycode);
// }

void	rotate(t_zip *zip, int keycode);

int	key_hook(int keycode, t_zip *zip)
{
	const t_key_type	key_type = get_key(keycode);

	if (key_type == ModeChange)
		change_mode(zip);
	else if (key_type == Free)
		change_select(zip);
	else if (key_type == Exit)
	{
		mlx_destroy_window(zip->mlx, zip->mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (key_type == Zoom)
		zoom(zip, keycode);
	else if (key_type == Translate)
		move(zip, keycode);
	// else if (key_type == Rotate)
	// 	rotate(zip, keycode)
	return (0);
}


int	mouse_hook(int button, int x, int y, t_zip *zip)
{
	if (button == 1 && zip->mdat->mode == OMODE && \
	zip->mdat->choice_obj == FALSE)
		object_picking(x, y, zip);
	return (0);
}

int	my_exit(void *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_hook(t_zip *zip)
{
	t_m_dat	*dat;

	dat = ft_malloc(sizeof(t_m_dat));
	dat->mode = CMODE;
	zip->mdat = dat;
	mlx_hook(zip->mlx->mlx_win, X_KEY_EXIT, 0, my_exit, NULL);
	mlx_key_hook(zip->mlx->mlx_win, key_hook, zip);
	mlx_mouse_hook(zip->mlx->mlx_win, mouse_hook, zip);	
}
