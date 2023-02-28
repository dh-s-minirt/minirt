/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:12:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 17:13:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	cone_mapping(t_hit_rec *cur_h_rec)
{
	const t_cone		*cn = (t_cone *)cur_h_rec->object;
	const t_mat4		local_cord = _normal_cord_(cn->nor_vector);
	const t_vec			pc = vec_sub(cur_h_rec->contact_point, \
	cn->center);
	const t_vec			pc_prime = vec_sub(cur_h_rec->contact_point, \
	vec_add(cn->center, vec_mul(cn->nor_vector, (vec_dot(pc, \
	cn->nor_vector)))));

	cur_h_rec->u = 1 - asin(fabs(vec_dot(get_y_cord(local_cord), pc_prime)) \
	/ vec_length(pc_prime)) / PI;
	cur_h_rec->v = fabs(vec_dot(pc, cn->nor_vector)) / cn->height;
}

void	get_uv(t_hit_rec *cur_h_rec, double plane_scale, int is_check)
{
	if (cur_h_rec->obj_type == SPHERE)
		spherical_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == PLANE)
		planar_mapping(cur_h_rec, plane_scale);
	else if (cur_h_rec->obj_type == DISK)
		disk_mapping(cur_h_rec, is_check);
	else if (cur_h_rec->obj_type == CYLINDER)
		cy_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == CONE)
		cone_mapping(cur_h_rec);
	else
		return ;
}
