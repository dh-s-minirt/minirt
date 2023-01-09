/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:11:41 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/01/09 16:21:48 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "../mini_rt.h"

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_sub(v, vec_mul(n, 2 * vec_dot(v, n))));
}

// t_color	ray_color(t_info_data *data)
// {
// }

// t_color	point_light_get(t_info_data *data)
// {
// }

// t_color	phong_lighting(t_info_data *data)
// {
// 	t_color	light_color;

// 	light_color = vec(0, 0, 0);
// 	light_color = vec_add(light_color, point_light_get(data));
// 	// hit_record에 저장된 오브젝트의 반사율과 곱해준다. 
// 	//return (vec_less(vec_mul(light_color, ), vec(1, 1, 1)))
// 	return (light_color);
// }