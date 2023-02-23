/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:01 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/24 03:51:29 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	_shade_reflect(t_hit_rec hit_rec, t_info_data *data, int depth, \
t_ray ray)
{
	const t_vec	reflect = vec_unit(v_reflect(ray.dir, hit_rec.hit_normal));
	t_ray		reflect_ray;

	reflect_ray.dir = vec_copy(reflect);
	reflect_ray.origin = vec_add(hit_rec.contact_point, \
	vec_mul(hit_rec.hit_normal, BIAS));
	return (ray_casting(reflect_ray, data, depth + 1));
}

// t_color	_shade_uv(t_hit_rec hit_rec, t_info_data *data)
// {
// 	const double	scale_u = 5.0;
// 	const double	scale_v = 5.0;
// 	const double	pattern = (cos(hitTexCoordinates.y * 2 * M_PI * scaleT) * sin(hitTexCoordinates.x * 2 * M_PI * scaleS) + 1) * 0.5; // 사인파 패턴 계산 
// hitColor += vis * pattern * lightIntensity * std::max(0.f, hitNormal.dotProduct(-lightDir));
// }