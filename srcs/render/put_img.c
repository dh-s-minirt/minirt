/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:23:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/13 15:25:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= SCREEN_WIDTH && y <= SCREEN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x \
		* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_my_mlx	init_mlx(void)
{
	t_my_mlx	my_mlx;

	my_mlx.mlx = mlx_init();
	my_mlx.mlx_win = mlx_new_window(my_mlx.mlx, SCREEN_HEIGHT, SCREEN_WIDTH, \
	"rt : ");
	my_mlx.img.img = mlx_new_image(my_mlx.mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	my_mlx.img.addr = mlx_get_data_addr(my_mlx.img.img, \
	&(my_mlx.img.bits_per_pixel), &(my_mlx.img.line_length), \
	&(my_mlx.img.endian));
}

int	write_color(int t, t_vec *pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color->x) << 16 | \
		(int)(255 * pixel_color->y) << 8 | (int)(255 * pixel_color->z));
}
