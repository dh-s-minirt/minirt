/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:40:32 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 01:47:11 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	draw_frame(t_mlx_data *data)
{
	draw_line((t_point){0xffffff, 400, 1, 0}, \
	(t_point){0xffffff, 400, SCREEN_HEIGHT + 200, 0}, data);
	draw_line((t_point){0xffffff, 1, 200, 0}, \
	(t_point){0xffffff, SCREEN_WIDTH + 600, 200, 0}, data);
}

void	draw_title(t_my_mlx *my_mlx)
{
	draw_xpm(my_mlx, "./ppm/Title.xpm", 0, 0);
}

void	draw_sidebar(t_my_mlx *my_mlx)
{
	draw_xpm(my_mlx, "./ppm/sidebar.xpm", 0, TITLE_HIGHT);
}

void	draw_topbar(t_my_mlx *my_mlx, t_m_dat mdat)
{
	if (mdat.mode == CMODE)
	{
		if (mdat.choice_obj == TRUE)
			draw_xpm(my_mlx, "./ppm/camera_select.xpm", TITLE_WIDTH, 0);
		else
			draw_xpm(my_mlx, "./ppm/camera_no.xpm", TITLE_WIDTH, 0);
	}
	else
	{
		if (mdat.choice_obj == TRUE)
			draw_xpm(my_mlx, "./ppm/obj_select.xpm", TITLE_WIDTH, 0);
		else
			draw_xpm(my_mlx, "./ppm/obj_no.xpm", TITLE_WIDTH, 0);
	}
}

void	draw_xpm(t_my_mlx *my_mlx, char *xpm, int x, int y)
{
	t_mlx_data		img;
	int				w_h[2];
	int				i;
	int				j;
	unsigned int	*p;

	i = -1;
	img.img = mlx_xpm_file_to_image(my_mlx->mlx, xpm, &w_h[0], &w_h[1]);
	img.addr = mlx_get_data_addr(img.img, \
	&img.bits_per_pixel, &img.line_length, &img.endian);
	while (++i < w_h[1])
	{
		j = -1;
		while (++j < w_h[0])
		{
			p = (unsigned int *)&my_mlx->img.addr[(i + y) * my_mlx->\
			img.line_length + (j + x) * (my_mlx->img.bits_per_pixel / 8)];
			*p = *(unsigned int *)&img.addr[i * img.line_length + j * \
			(img.bits_per_pixel / 8)];
		}
	}
}
