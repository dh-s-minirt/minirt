/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:15:06 by idaegyu           #+#    #+#             */
/*   Updated: 2023/03/07 13:50:30 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	rot_upd_child_center(t_zip *zip)
{
	t_vec	*child_p;
	t_vec	*center;
	t_vec	*normal;
	double	*height;

	if (zip->mdat->obj_type != CONE && zip->mdat->obj_type != CYLINDER)
		return ;
	center = get_center(zip->mdat->object, zip->mdat->obj_type);
	normal = get_normal(zip->mdat->object, zip->mdat->obj_type);
	height = get_height(zip->mdat->object, zip->mdat->obj_type);
	if (zip->mdat->obj_type == CONE)
		child_p = get_center(((t_cone *)zip->mdat->object)->bot, DISK);
	else
		child_p = get_center(((t_cylinder *)zip->mdat->object)->top, DISK);
	if (child_p == NULL)
		return ;
	*child_p = vec_add(*center, vec_mul(*normal, *height));
}

void	rot_upd_nor_z(t_zip *zip, double theta)
{
	t_vec	*normal_p;
	t_vec	*child_p;

	normal_p = get_normal(zip->mdat->object, zip->mdat->obj_type);
	*normal_p = _rotate_vec_(theta, 'z', *normal_p);
	if (zip->mdat->obj_type == CONE)
	{
		child_p = get_normal(((t_cone *)zip->mdat->object)->bot, DISK);
		*child_p = *normal_p;
	}
	if (zip->mdat->obj_type == CYLINDER)
	{
		child_p = get_normal(((t_cylinder *)zip->mdat->object)->bot, DISK);
		if (child_p == NULL)
			return ;
		*child_p = *normal_p;
		child_p = get_normal(((t_cylinder *)zip->mdat->object)->top, DISK);
		*child_p = *normal_p;
	}
}

void	_sub_rot_sub_(t_zip *zip, double theta, t_vec *normal_p)
{
	double	*child_phi;
	t_vec	*child_p;

	child_p = get_normal(((t_cylinder *)zip->mdat->object)->bot, DISK);
	if (child_p == NULL)
		return ;
	*child_p = *normal_p;
	child_p = get_normal(((t_cylinder *)zip->mdat->object)->top, DISK);
	*child_p = *normal_p;
	child_phi = get_phi(((t_cylinder *)zip->mdat->object)->bot, DISK);
	*child_phi = circle_clamp(*child_phi + theta, 0, 360);
	child_phi = get_phi(((t_cylinder *)zip->mdat->object)->top, DISK);
	*child_phi = circle_clamp(*child_phi + theta, 0, 360);
}