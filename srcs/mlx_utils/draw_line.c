/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:12:15 by idaegyu           #+#    #+#             */
/*   Updated: 2023/03/03 23:57:55 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	init_delta(t_point p1, t_point p2, t_delta *delta)
{
	delta->dx = abs(p2.x - p1.x);
	delta->dy = -abs(p2.y - p1.y);
	if (p1.x < p2.x)
		delta->step_x = 1;
	else
		delta->step_x = -1;
	if (p1.y < p2.y)
		delta->step_y = 1;
	else
		delta->step_y = -1;
	delta->error = delta->dx + delta->dy;
}

void	draw_line(t_point p1, t_point p2, t_mlx_data *data)
{
	t_delta	delta;

	init_delta(p1, p2, &delta);
	while (1)
	{
		my_mlx_pixel_put(data, p1.x, p1.y, \
		p1.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		delta.e2 = 2 * delta.error;
		if (delta.e2 >= delta.dy)
		{
			if (p1.x == p2.x)
				break ;
			delta.error += delta.dy;
			p1.x += delta.step_x;
		}
		if (delta.e2 <= delta.dx)
		{
			if (p1.y == p2.y)
				break ;
			delta.error += delta.dx;
			p1.y += delta.step_y;
		}	
	}
}

void	draw_frame(t_mlx_data *data)
{
	draw_line((t_point){0xffffff, 400, 1, 0}, \
	(t_point){0xffffff, 400, SCREEN_HEIGHT + 200, 0}, data);
	draw_line((t_point){0xffffff, 1, 200, 0}, \
	(t_point){0xffffff, SCREEN_WIDTH + 600, 200, 0}, data);
}

void	draw_title(t_my_mlx *my_mlx)
{
	draw_xpm(my_mlx, "./ppm/Title.xpm");
}

void	draw_xpm(t_my_mlx *my_mlx, char *xpm)
{
	t_mlx_data		img;
	int				w_h[2];
	int				i;
	int				j;
	int				color;
	unsigned int	*p;

	i = -1;
	img.img = mlx_xpm_file_to_image(my_mlx->mlx, xpm, &w_h[0], &w_h[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (++i < w_h[1])
	{
		j = -1;
		while (++j < w_h[0])
		{
			p = (unsigned int *)&my_mlx->img.addr\
			[i * my_mlx->img.line_length + j * (my_mlx->img.bits_per_pixel / 8)];
			color = *(unsigned int*)&img.addr[i * img.line_length + j * \
			(img.bits_per_pixel / 8)];
			*p = color;
		}
	}
}