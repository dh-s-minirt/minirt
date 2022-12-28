/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 17:49:27 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "./parsing/parsing.h"
#include "./color/color.h"
#include "./mlx_utils.h"
#include <stdio.h>

void	print_data(t_info_data *data)
{
	t_node	*tmp;

	printf("AM_LIGHT: %lf %d,%d,%d\n", data->am_light.ratio_in_range,
			get_r(data->am_light.color_range), get_g(data->am_light.color_range), get_b(data->am_light.color_range));
	printf("Camera: %lf,%lf,%lf %lf,%lf,%lf %d\n", data->camera.coordinates.x, data->camera.coordinates.y, data->camera.coordinates.z,
			data->camera.nor_vector.x, data->camera.nor_vector.y, data->camera.nor_vector.z, data->camera.fov);
	printf("Light: %lf,%lf,%lf %lf %d,%d,%d\n", data->light.coordinates.x, data->light.coordinates.y, data->light.coordinates.z,
			data->light.ratio_in_range, get_r(data->light.color_range), get_g(data->light.color_range), get_b(data->light.color_range));
	tmp = data->shape;
	while (tmp)
	{
		if (tmp->type == SPHERE)
		{
			printf ("Sphere: %lf,%lf,%lf %lf %d,%d,%d\n", ((t_sphere *)tmp->data)->center.x, ((t_sphere *)tmp->data)->center.y, ((t_sphere *)tmp->data)->center.z,
					((t_sphere *)tmp->data)->diameter, get_r(((t_sphere *)tmp->data)->color_range), get_g(((t_sphere *)tmp->data)->color_range), \
					get_b(((t_sphere *)tmp->data)->color_range));
		}
		else if (tmp->type == PLANE)
		{
			printf ("Plane: %lf,%lf,%lf %lf,%lf,%lf %d,%d,%d\n", ((t_plain *)tmp->data)->coordinates.x, ((t_plain *)tmp->data)->coordinates.y, ((t_plain *)tmp->data)->coordinates.z,
					((t_plain *)tmp->data)->nor_vector.x, ((t_plain *)tmp->data)->nor_vector.y, ((t_plain *)tmp->data)->nor_vector.z, \
					get_r(((t_plain *)tmp->data)->color_range), get_g(((t_plain *)tmp->data)->color_range), get_b(((t_plain *)tmp->data)->color_range));
		}
		else if (tmp->type == CYLINDER)
		{
			printf ("Cylinder: %lf,%lf,%lf %lf,%lf,%lf %lf %lf %d,%d,%d\n", ((t_cylinder *)tmp->data)->coordinates.x, ((t_cylinder *)tmp->data)->coordinates.y, ((t_cylinder *)tmp->data)->coordinates.z,
					((t_cylinder *)tmp->data)->nor_vector.x, ((t_cylinder *)tmp->data)->nor_vector.y, ((t_cylinder *)tmp->data)->nor_vector.z, \
					((t_cylinder *)tmp->data)->diameter, ((t_cylinder *)tmp->data)->height, get_r(((t_cylinder *)tmp->data)->color_range), \
					get_g(((t_cylinder *)tmp->data)->color_range), get_b(((t_cylinder *)tmp->data)->color_range));
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_info_data	data;

	if (argc != 2)
		return (0);
	data.shape = NULL;
	get_info_data(argv[1], &data);
	return (0);
}
