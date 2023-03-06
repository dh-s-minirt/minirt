/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:48:16 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 20:13:40 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	rot_upd_nor_x(t_zip *zip, double theta);
void	rot_upd_nor_y(t_zip *zip, double theta);
void	rot_upd_nor_z(t_zip *zip, double theta);

void	rot_update_normal(t_zip *zip, char mode, double theta)
{
	if (mode == 'x')
		rot_upd_nor_x(zip, theta);
	if (mode == 'y')
		rot_upd_nor_y(zip, theta);
	if (mode == 'z')
		rot_upd_nor_z(zip, theta);
}

void	rotate(t_zip *zip, int keycode)
{
	if (zip->mdat->mode == CMODE)
		camera_rotate(zip, keycode);
	else
		object_rotate(zip, keycode);
}

void	object_rotate(t_zip *zip, int keycode)
{
	if (zip->mdat->obj_type == DISK)
	{
		zip->mdat->obj_type = ((t_disk *)(zip->mdat->object))->parent_type;
		zip->mdat->object = ((t_disk *)(zip->mdat->object))->parent;
		rotate(zip, keycode);
		return ;
	}
	if (keycode == KEY_ROT_XM)
		rot_update_normal(zip, 'x', -15);
	if (keycode == KEY_ROT_XP)
		rot_update_normal(zip, 'x', 15);
	if (keycode == KEY_ROT_YM)
		rot_update_normal(zip, 'y', -15);
	if (keycode == KEY_ROT_YP)
		rot_update_normal(zip, 'y', 15);
	if (keycode == KEY_ROT_ZM)
		rot_update_normal(zip, 'z', -15);
	if (keycode == KEY_ROT_ZP)
		rot_update_normal(zip, 'z', 15);
	rot_upd_child_center(zip);
	start_draw(zip);
}

void	rot_upd_nor_x(t_zip *zip, double theta)
{
	t_vec	*normal_p;
	t_vec	*child_p;

	normal_p = get_normal(zip->mdat->object, zip->mdat->obj_type);		
	*normal_p = _rotate_vec_(theta, 'x', *normal_p);
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

void	rot_upd_nor_y(t_zip *zip, double theta)
{
	t_vec	*normal_p;
	t_vec	*child_p;
	double	*phi;
	double	*child_phi;

	normal_p = get_normal(zip->mdat->object, zip->mdat->obj_type);
	*normal_p = _rotate_vec_(theta, 'y', *normal_p);
	phi = get_phi(zip->mdat->object, zip->mdat->obj_type);
	*phi = circle_clamp(*phi + theta, 0, 180);
	if (zip->mdat->obj_type == CONE)
	{
		child_p = get_normal(((t_cone *)zip->mdat->object)->bot, DISK);
		*child_p = *normal_p;
		child_phi = get_phi(((t_cone *)zip->mdat->object)->bot, DISK);
		*child_phi = circle_clamp(*child_phi + theta, 0, 360);
	}
	if (zip->mdat->obj_type == CYLINDER)
	{
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


