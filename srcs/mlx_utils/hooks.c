/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/06 04:40:19 by daegulee         ###   ########.fr       */
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
	else if (key_type == Rotate)
		rotate(zip, keycode);
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
