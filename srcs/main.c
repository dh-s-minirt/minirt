/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/07 08:05:59 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "./parsing/parsing.h"
#include "./color/color.h"
#include "./mlx_utils.h"
#include <stdio.h>
#include "./settings/setting.h"

void	print_data(t_info_data *data)
{
	t_light_node *tmp;

	printf("camera : center = %lf %lf %lf, nor_vec = %lf %lf %lf, fov %d\n", data->camera.center.x, data->camera.center.y, data->camera.center.z,\
		data->camera.nor_vector.x, data->camera.nor_vector.y, data->camera.nor_vector.z, data->camera.fov);
	tmp = data->light_node;
	while (tmp)
	{
		if(tmp->type == AM_LIGHT)
		{
			t_am_light *light = tmp->data;
			printf("am_light : %lf %lf %lf\n", light->color.x, light->color.y, light->color.z);
		}
		else if (tmp->type == LIGHT)
		{
			t_light *light = tmp->data;
			printf("light : center = %lf %lf %lf ratio = %lf color = %lf %lf %lf\n", light->center.x, light->center.y, light->center.z,\
				light->ratio, light->color.x, light->color.y, light->color.z);
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_info_data	data;
	t_settings	set;

	if (argc != 2)
		return (0);
	data.objects = NULL;
	data.light_node = NULL;
	// data.canvas = canvas_new(CANVAS_WIDTH, CANVAS_HEIGHT);
	get_info_data(argv[1], &data);
	_init_setting_(data);
	print_data(&data);
	return (0);
}
