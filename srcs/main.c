/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/06 23:49:31 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "struct.h"
#include "./settings/setting.h"
#include "./hit_record/hit_record.h"
#include "./render/render.h"
#include "./mlx_utils/mlx_util.h"
#include "./parsing/parsing.h"
#include <stdlib.h>

static void	_first_render(t_zip *zip)
{
	draw_title(zip->mlx);
	draw_sidebar(zip->mlx);
	draw_topbar(zip->mlx, (t_m_dat){CMODE, FALSE, NULL, 0});
	multi_thread(zip->set, zip->data, zip->mlx);
	draw_frame(&zip->mlx->img);
	mlx_put_image_to_window(zip->mlx->mlx, \
	zip->mlx->mlx_win, zip->mlx->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_info_data	data;
	t_settings	set;
	t_my_mlx	my_mlx;
	t_zip		zip;

	get_info_data(argv[1], &data, argc);
	set = _init_setting_(data.camera);
	my_mlx = init_mlx();
	zip.data = &data;
	zip.mlx = &my_mlx;
	zip.set = set;
	_first_render(&zip);
	my_hook(&zip);
	mlx_loop(my_mlx.mlx);
	return (0);
}
