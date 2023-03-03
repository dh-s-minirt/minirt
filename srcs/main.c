/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 22:00:27 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "struct.h"
#include "./settings/setting.h"
#include "./hit_record/hit_record.h"
#include "./render/render.h"
#include "./mlx_utils/mlx_util.h"
#include "./parsing/parsing.h"

void	my_hook(t_zip *zip);
int		key_hook(int keycode, t_zip *vars);

t_zip	*_make_zip(t_settings set, \
t_info_data *data, \
t_my_mlx	*mlx, \
int row)
{
	t_zip	*zip;

	zip = ft_malloc(sizeof(t_zip));
	zip->set = set;
	zip->data = data;
	zip->mlx = mlx;
	zip->start_row = row;
	return (zip);
}

static	void	multi_thread(t_settings set, t_info_data *data, \
t_my_mlx *my_mlx)
{
	pthread_t	tid[THREAD_N];
	int			i;
	t_zip		*zip[THREAD_N];

	i = -1;
	while (++i < THREAD_N)
	{
		zip[i] = _make_zip(set, data, my_mlx, \
		i * set.screen_height / THREAD_N);
		pthread_create(&tid[i], NULL, render, (void *)zip[i]);
	}
	i = -1;
	while (++i < THREAD_N)
		pthread_join(tid[i], NULL);
	i = -1;
	while (++i < THREAD_N)
		free(zip[i]);
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
	// draw_title(&my_mlx);
	multi_thread(set, &data, &my_mlx);
	draw_frame(&my_mlx.img);
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.mlx_win, my_mlx.img.img, 0, 0);
	zip.data = &data;
	zip.mlx = &my_mlx;
	zip.set = set;
	my_hook(&zip);
	mlx_loop(my_mlx.mlx);
	return (0);
}
