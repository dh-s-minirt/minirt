/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:11:22 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 17:28:34 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	_check_pattern_(t_hit_rec *cur_h_rec, double check_n)
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
	const t_sphere	*sp = (t_sphere *)cur_h_rec->object;
	const t_vec		pc = vec_sub(cur_h_rec->contact_point, \
	sp->center);
	const double	theta = atan2(pc.z, \
	pc.x);
	const double	phi = asin(pc.y / vec_length(pc));

	cur_h_rec->u = theta / (PI * 2) + 0.5;
	cur_h_rec->v = phi / PI + 0.5;
}

void	planar_mapping(t_hit_rec *cur_h_rec, double scale)
{
	const t_plane	*plane = (t_plane *)cur_h_rec->object;
	const t_mat4	local_cord = _normal_cord_(plane->nor_vector);
	const t_vec		local_x = get_x_cord(local_cord);
	const t_vec		local_y = get_y_cord(local_cord);

	cur_h_rec->u = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_x)), \
	scale) / scale;
	cur_h_rec->v = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_y)), \
	scale) / scale;
}

void	disk_mapping(t_hit_rec *cur_h_rec, int is_check)
{
	const t_disk	*disk = (t_disk *)cur_h_rec->object;
	const t_mat4	local_cord = _normal_cord_(disk->nor_v);
	const t_vec		local_y = get_y_cord(local_cord);
	const t_vec		local_x = get_x_cord(local_cord);
	const t_vec		pc = vec_sub(cur_h_rec->contact_point, \
	disk->center);

	if (is_check)
	{
		cur_h_rec->u = 0.5 + asin(vec_dot(local_y, pc) \
	/ vec_length(pc)) / PI;
		return ;
	}
	cur_h_rec->u = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_x)), \
	10) / 10;
	cur_h_rec->v = fmod(fabs(vec_dot(cur_h_rec->contact_point, local_y)), \
	10) / 10;
}

void	cy_mapping(t_hit_rec *cur_h_rec)
{
	const t_cylinder	*cy = (t_cylinder *)cur_h_rec->object;
	const t_mat4		local_cord = _normal_cord_(cy->nor_vector);
	const t_vec			pc = vec_sub(cur_h_rec->contact_point, \
	cy->center);
	const t_vec			pc_prime = vec_sub(cur_h_rec->contact_point, \
	vec_add(cy->center, vec_mul(cy->nor_vector, fabs(vec_dot(pc, \
	cy->nor_vector)))));

	cur_h_rec->u = 1 - asin(fabs(vec_dot(get_y_cord(local_cord), pc_prime)) \
	/ vec_length(pc_prime)) / PI;
	cur_h_rec->v = fabs(vec_dot(pc, cy->nor_vector)) / cy->height;
}
