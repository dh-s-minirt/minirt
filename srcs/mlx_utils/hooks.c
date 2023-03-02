/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/02 15:04:44 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "../mlx/mlx.h"
#include "../settings/setting.h"

typedef struct s_zip
{
	t_settings	set;
	t_info_data	*data;
	t_my_mlx	*mlx;
	int			start_row;
}	t_zip;

int	key_hook(int keycode, t_zip *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->mlx->mlx_win);
		exit(0);
	}
	// else if (keycode == LEFT || keycode == RIGHT \
	// 	|| keycode == UP || keycode == DOWN)
	// 	move(vars, keycode);
	return (0);
}

// void	move(t_vars *vars, int keycode)
// {
// 	long double	e;

// 	e = vars->size / WIN_HEIGHT;
// 	if (keycode == LEFT)
// 		vars->point_x -= vars->size * 0.1;
// 	else if (keycode == RIGHT)
// 		vars->point_x += vars->size * 0.1;
// 	else if (keycode == UP)
// 		vars->point_y += vars->size * 0.1;
// 	else
// 		vars->point_y -= vars->size * 0.1;
// 	start_draw(vars);
// }


// img ㅅㅐ로 만만들들어어야됨
// void	start_draw(t_vars *vars)
// {
// 	t_data	img;

// 	init_img(&img, vars);
// 	put_pixel(&img, vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
// }


// int	mouse_hook(int button, int x, int y, t_vars *vars)
// {
// 	if (button == 4)
// 		zoom_in(x, y, vars);
// 	else if (button == 5)
// 		zoom_out(x, y, vars);
// 	else if (button == 1 || button == 2)
// 		change_color(vars);
// 	return (0);
// }

// void	zoom_in(int x, int y, t_vars *vars)
// {
// 	long double	e;

// 	vars->size *= 0.9;
// 	e = vars->size / WIN_HEIGHT;
// 	vars->point_x += (x - WIN_WIDTH / 2) * e * 0.1;
// 	vars->point_y += (WIN_HEIGHT / 2 - y) * e * 0.1;
// 	start_draw(vars);
// }

// void	zoom_out(int x, int y, t_vars *vars)
// {
// 	long double	e;

// 	vars->size *= 1.1;
// 	e = vars->size / WIN_HEIGHT;
// 	vars->point_x -= (x - WIN_WIDTH / 2) * e * 0.1;
// 	vars->point_y -= (WIN_HEIGHT / 2 - y) * e * 0.1;
// 	start_draw(vars);
// }