/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:12:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/07 14:46:46 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	cone_mapping(t_hit_rec *cur_h_rec)
{
	const t_cone		*cn = (t_cone *)cur_h_rec->object;
	const t_mat4		local_cord = \
	_mul_mat_(_normal_cord_(cn->nor_vector), _rotate_mat_(cn->phi, 'y'));
	const t_vec			pc = vec_sub(cur_h_rec->contact_point, \
	cn->center);
	const t_vec			pc_prime = vec_unit(vec_sub(pc, \
	vec_mul(cn->nor_vector, (vec_dot(pc, \
	cn->nor_vector)))));

	cur_h_rec->u = 0.50 + asin(vec_dot(get_y_cord(local_cord), pc_prime)) \
	/ (2 * PI);
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

void	get_normal_map(t_hit_rec *hit_rec, t_ppm *normal_ppm)
{
	double			x;
	double			y;
	t_vec			local_normal;
	const t_mat4	local_cord = _normal_cord_(hit_rec->hit_normal);

	x = clamp(hit_rec->u * (normal_ppm->width - 1), 0, normal_ppm->width - 1);
	y = clamp(hit_rec->v * (normal_ppm->height - 1), 0, normal_ppm->height - 1);
	local_normal = vec_mul(vec_sub((normal_ppm->map)[(int)round(y) * \
	normal_ppm->width + (int)round(x) - 1], vec(0.5, 0.5, 0.5)), 2);
	hit_rec->hit_normal = _mul_vec_mat(local_cord, \
		vec_2_arr_vec3(local_normal));
}
