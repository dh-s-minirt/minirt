/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:11:22 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/25 23:18:57 by daegulee         ###   ########.fr       */
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
	const t_mat4	local_cord = _normal_cord_(cur_h_rec->hit_normal);
	double			local_x;
	double			local_y;

	local_x = local_cord.m[0][0] * cur_h_rec->contact_point.x + \
	local_cord.m[0][1] * cur_h_rec->contact_point.y + local_cord.m[0][2] * \
	cur_h_rec->contact_point.z;
	local_y = local_cord.m[1][0] * cur_h_rec->contact_point.x + \
	local_cord.m[1][1] * cur_h_rec->contact_point.y + local_cord.m[1][2] * \
	cur_h_rec->contact_point.z;
	cur_h_rec->u = fabs(fmod(local_x, 100)) / 100;
	cur_h_rec->v = fabs(fmod(local_y, 100)) / 100;
	_uv_pattern_(cur_h_rec, 5.0);
}

void	disk_mapping(t_hit_rec *cur_h_rec)
{
	const t_mat4	local_cord = _normal_cord_(cur_h_rec->hit_normal);
	double			local_x;
	double			local_y;
	double			local_z;
	const t_vec		pc = vec_sub(cur_h_rec->contact_point, \
	cur_h_rec->hit_center);

	local_x = local_cord.m[0][0] * pc.x + \
	local_cord.m[0][1] * pc.y + local_cord.m[0][2] * \
	pc.z;
	local_y = local_cord.m[1][0] * pc.x + \
	local_cord.m[1][1] * pc.y + local_cord.m[1][2] * \
	pc.z;
	local_z = local_cord.m[2][0] * pc.x + \
	local_cord.m[2][1] * pc.y + local_cord.m[2][2] * \
	pc.z;
	cur_h_rec->v = 1 - asin(local_y / vec_length(pc)) / PI;
	_uv_pattern_(cur_h_rec, 5.2);
}

void	cy_mapping(t_hit_rec *cur_h_rec)
{
	const t_mat4	local_cord = _normal_cord_(cur_h_rec->hit_normal);
	double			local_x;
	double			local_y;
	double			local_z;
	double			theta;

	local_x = local_cord.m[0][0] * cur_h_rec->contact_point.x + \
	local_cord.m[0][1] * cur_h_rec->contact_point.y + local_cord.m[0][2] * \
	cur_h_rec->contact_point.z;
	local_y = local_cord.m[1][0] * cur_h_rec->contact_point.x + \
	local_cord.m[1][1] * cur_h_rec->contact_point.y + local_cord.m[1][2] * \
	cur_h_rec->contact_point.z;
	local_z = local_cord.m[2][0] * cur_h_rec->contact_point.x + \
	local_cord.m[2][1] * cur_h_rec->contact_point.y + local_cord.m[2][2] * \
	cur_h_rec->contact_point.z;
	theta = atan2(local_x, local_z);
	cur_h_rec->u = 0.5 + theta / (2 * PI);
	cur_h_rec->v = fabs(fmod(local_y, 50)) / 50;
	_uv_pattern_(cur_h_rec, 10);
}

	// const double	theta = atan2(cur_h_rec->hit_normal.z, \
	// cur_h_rec->hit_normal.x);

	// cur_h_rec->u = 0.5 + theta / (2 * PI);
void	cone_mapping(t_hit_rec *cur_h_rec)
{
	const t_mat4	local_cord = _normal_cord_(cur_h_rec->hit_normal);
	const t_vec		local_x = get_x_cord(local_cord);
	const t_vec		local_z = get_z_cord(local_cord);
	const t_vec		pc = vec_sub(cur_h_rec->contact_point, \
	cur_h_rec->hit_center);

	cur_h_rec->u = 0.5 + atan2(vec_dot(local_z, pc), vec_dot(local_x, pc));
	cur_h_rec->v = fmod(fabs(vec_dot(pc, cur_h_rec->hit_normal)), 10) / 10;  
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
