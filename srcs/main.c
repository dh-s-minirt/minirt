/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 03:11:32 by daegulee         ###   ########.fr       */
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

typedef struct s_mode
{
	t_bool	mode;
	t_bool	choice_obj;
}	t_mode;

typedef struct s_zip
{
	t_settings	set;
	t_info_data	*data;
	t_my_mlx	*mlx;
	int			start_row;
	int			*choice_obj;
	t_mode		*mode;
}	t_zip;

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
	multi_thread(set, &data, &my_mlx);
	mlx_put_image_to_window(my_mlx.mlx, \
	my_mlx.mlx_win, my_mlx.img.img, 100, 100);
	zip.data = &data;
	zip.mlx = &my_mlx;
	zip.set = set;
	mlx_key_hook(my_mlx.mlx_win, key_hook, &zip);
	// mlx_mouse_hook(my_mlx.mlx_win, mouse_hook, &zip);
	mlx_loop(my_mlx.mlx);
	return (0);
}
