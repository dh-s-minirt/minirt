/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/28 00:45:23 by daegulee         ###   ########.fr       */
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

typedef struct s_zip
{
	t_settings	set;
	t_info_data	*data;
	t_my_mlx	*mlx;
	int			start_row;
}	t_zip;

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

int	main(int argc, char **argv)
{
	t_info_data	data;
	t_settings	set;
	t_my_mlx	my_mlx;
	pthread_t	tid[THREAD_N];
	int			i;

	i = -1;
	get_info_data(argv[1], &data, argc);
	set = _init_setting_(data);
	my_mlx = init_mlx();
	while (++i < THREAD_N)
		pthread_create(&tid[i], NULL, \
		render, \
		(void *)_make_zip(set, &data, &my_mlx, \
		i * set.screen_height / THREAD_N));
	i = -1;
	while (++i < THREAD_N)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(my_mlx.mlx, \
	my_mlx.mlx_win, my_mlx.img.img, 0, 0);
	mlx_loop(my_mlx.mlx);
	return (0);
}
