/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:15:06 by idaegyu           #+#    #+#             */
/*   Updated: 2023/03/06 04:45:00 by idaegyu          ###   ########.fr       */
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
	*child_p = vec_add(*center, vec_mul(*normal, *height));
}