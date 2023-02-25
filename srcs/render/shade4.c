/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:11:22 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 02:22:53 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	_uv_pattern_(t_hit_rec *cur_h_rec, double check_n)
{
	const double	checker_width = check_n;
	const double	checker_height = check_n;
	const double	on_u = modulo(cur_h_rec->u * checker_width);
	const double	on_v = modulo(cur_h_rec->v * checker_height);

	if (((on_u < 0.5) + (on_v < 0.5)) % 2 == 0)
		cur_h_rec->albedo = vec(1, 1, 1);
}

void	spherical_mapping(t_hit_rec *cur_h_rec)
{
	const double	theta = atan2(cur_h_rec->hit_normal.z, \
	cur_h_rec->hit_normal.x);
	const double	phi = asin(cur_h_rec->hit_normal.y);

	cur_h_rec->u = 0.5 + theta / (2 * PI);
	cur_h_rec->v = 1 - phi / PI;
	_uv_pattern_(cur_h_rec, 5.0);
}

// void	planar_mapping(t_hit_rec *cur_h_rec)
// {
// 	cur_h_rec->u = fmod(cur_h_rec->contact_point.x, 1);
// 	cur_h_rec->v = fmod(cur_h_rec->contact_point.z, 1);
// }

void	planar_mapping(t_hit_rec *cur_h_rec)
{
	const t_plane	*plane = (t_plane *)cur_h_rec->object;
	const t_mat4	local_cord = _normal_cord_(plane->nor_vector);
	const t_vec		local_x = get_x_cord(local_cord);
	const t_vec		local_y = get_y_cord(local_cord);

	cur_h_rec->u = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_x)), \
	100) / 100;
	cur_h_rec->v = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_y)), \
	100) / 100;
	_uv_pattern_(cur_h_rec, 5.0);
}

void	disk_mapping(t_hit_rec *cur_h_rec)
{
	const t_disk	*disk = (t_disk *)cur_h_rec->object;
	const t_mat4	local_cord = _normal_cord_(disk->nor_v);
	const t_vec		local_y = get_y_cord(local_cord);
	const t_vec		pc = vec_sub(cur_h_rec->contact_point, \
	disk->center);

	cur_h_rec->u = 1 - asin(vec_dot(local_y, pc) \
	/ vec_length(pc)) / PI;
	_uv_pattern_(cur_h_rec, 5);
}

void	cy_mapping(t_hit_rec *cur_h_rec)
{
	const t_cylinder	*cy = (t_cylinder *)cur_h_rec->object;
	const t_mat4		local_cord = _normal_cord_(cy->nor_vector);
	const t_vec			pc = vec_sub(cur_h_rec->contact_point, \
	cy->center);
	const t_vec 		pc_prime = vec_sub(cur_h_rec->contact_point, \
	vec_add(cy->center, vec_mul(cy->nor_vector, fabs(vec_dot(pc, \
	cy->nor_vector)))));

	cur_h_rec->u = 1 - asin(fabs(vec_dot(get_y_cord(local_cord), pc_prime)) \
	/ vec_length(pc_prime)) / PI;
	cur_h_rec->v = fabs(vec_dot(pc, cy->nor_vector)) / cy->height;
	_uv_pattern_(cur_h_rec, 5);
}

// 	// const double	theta = atan2(cur_h_rec->hit_normal.z, \
// 	// cur_h_rec->hit_normal.x);

// 	// cur_h_rec->u = 0.5 + theta / (2 * PI);
void	cone_mapping(t_hit_rec *cur_h_rec)
{
	const t_cone		*cn = (t_cone *)cur_h_rec->object;
	const t_mat4		local_cord = _normal_cord_(cn->nor_vector);
	const t_vec			pc = vec_sub(cur_h_rec->contact_point, \
	cn->center);
	const t_vec 		pc_prime = vec_sub(cur_h_rec->contact_point, \
	vec_add(cn->center, vec_mul(cn->nor_vector, fabs(vec_dot(pc, \
	cn->nor_vector)))));

	cur_h_rec->u = 1 - asin(fabs(vec_dot(get_y_cord(local_cord), pc_prime)) \
	/ vec_length(pc_prime)) / PI;
	cur_h_rec->v = fabs(vec_dot(pc, cn->nor_vector)) / cn->height;
	_uv_pattern_(cur_h_rec, 5);
}

void	get_uv(t_hit_rec *cur_h_rec)
{
	if (cur_h_rec->obj_type == SPHERE)
		spherical_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == PLANE)
		planar_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == DISK)
		disk_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == CYLINDER)
		cy_mapping(cur_h_rec);
	else if (cur_h_rec->obj_type == CONE)
		cone_mapping(cur_h_rec);
	else
		return ;
}
