/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leehyunkyu <leehyunkyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 19:50:29 by leehyunkyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "./parsing/parsing.h"
#include "./color/color.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include "./settings/setting.h"
#include "./hit_record/hit_record.h"
#include "./render/render.h"

int key_hook(int keycode);
int mouse_hook(int button, int x, int y);

int	main(int argc, char **argv)
{
	t_info_data	data;
	t_settings	set;
	t_my_mlx	my_mlx;

	if (argc != 2)
		return (0);
	data.objects = NULL;
	data.lights = NULL;
	get_info_data(argv[1], &data);
	set = _init_setting_(data);
	my_mlx = init_mlx();
	render(set, &data, &my_mlx);
	mlx_put_image_to_window(my_mlx.mlx, \
	my_mlx.mlx_win, my_mlx.img.img, 0, 0);
	mlx_key_hook(my_mlx.mlx_win, key_hook, NULL);
	mlx_hook(my_mlx.mlx_win, 17, 0, mouse_hook, NULL);
	mlx_loop(my_mlx.mlx);
	return (0);
}
