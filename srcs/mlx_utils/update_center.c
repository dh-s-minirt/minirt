/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:57:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 20:07:23 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

void	update_center_z(t_zip *zip, long double e)
{
	t_vec	*center_p;
	t_vec	*child_p;

	center_p = get_center(zip->mdat->object, zip->mdat->obj_type);
	center_p->z += e;
	if (zip->mdat->obj_type == CONE)
	{
		child_p = get_center(((t_cone *)zip->mdat->object)->bot, DISK);
		child_p->z += e;
	}
	if (zip->mdat->obj_type == CYLINDER)
	{
		child_p = get_center(((t_cylinder *)zip->mdat->object)->bot, DISK);
		if (child_p == NULL)
			return ;
		child_p->z += e;
		child_p = get_center(((t_cylinder *)zip->mdat->object)->top, DISK);
		child_p->z += e;
	}
}

void	update_center_y(t_zip *zip, long double e)
{
	t_vec	*center_p;
	t_vec	*child_p;

	center_p = get_center(zip->mdat->object, zip->mdat->obj_type);
	center_p->y += e;
	if (zip->mdat->obj_type == CONE)
	{
		child_p = get_center(((t_cone *)zip->mdat->object)->bot, DISK);
		child_p->y += e;
	}
	if (zip->mdat->obj_type == CYLINDER)
	{
		child_p = get_center(((t_cylinder *)zip->mdat->object)->bot, DISK);
		if (child_p == NULL)
			return ;
		child_p->y += e;
		child_p = get_center(((t_cylinder *)zip->mdat->object)->top, DISK);
		child_p->y += e;
	}
}

void	update_center_x(t_zip *zip, long double e)
{
	t_vec	*center_p;
	t_vec	*child_p;

	center_p = get_center(zip->mdat->object, zip->mdat->obj_type);
	center_p->x += e;
	if (zip->mdat->obj_type == CONE)
	{
		child_p = get_center(((t_cone *)zip->mdat->object)->bot, DISK);
		child_p->x += e;
	}
	if (zip->mdat->obj_type == CYLINDER)
	{
		child_p = get_center(((t_cylinder *)zip->mdat->object)->bot, DISK);
		if (child_p == NULL)
			return ;
		child_p->x += e;
		child_p = get_center(((t_cylinder *)zip->mdat->object)->top, DISK);
		child_p->x += e;
	}
}
