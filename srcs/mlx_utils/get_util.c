/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:50:07 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 04:35:58 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

t_vec	*get_center(void *obj, t_obj_type type)
{
	if (type == PLANE)
		return (&((t_plane *)obj)->center);
	else if (type == SPHERE)
		return (&((t_sphere *)obj)->center);
	else if (type == CONE)
		return (&((t_cone *)obj)->center);
	else if (type == DISK)
		return (&((t_disk *)obj)->center);
	else
		return (&((t_cylinder *)obj)->center);
}

t_vec	*get_normal(void *obj, t_obj_type type)
{
	if (type == PLANE)
		return (&((t_plane *)obj)->nor_vector);
	else if (type == SPHERE)
		return (NULL);
	else if (type == CONE)
		return (&((t_cone *)obj)->nor_vector);
	else if (type == DISK)
		return (&((t_disk *)obj)->nor_v);
	else
		return (&((t_cylinder *)obj)->nor_vector);
}

double	*get_height(void *obj, t_obj_type type)
{
	if (type == CONE)
		return (&((t_cone *)obj)->height);
	else if (type == CYLINDER)	
		return (&((t_cylinder *)obj)->height);
	else
		return (NULL);
}

t_key_type	get_key(int keycode)
{
	t_key_type	type;

	if (keycode == KEY_C)
		type = ModeChange;
	else if (keycode == KEY_Q || keycode == KEY_A || \
	keycode == KEY_W || keycode == KEY_S || keycode == KEY_E || \
	keycode == KEY_D)
		type = Translate;
	else if (keycode == KEY_ROT_XP || keycode == KEY_ROT_XM || \
	keycode == KEY_ROT_YP || keycode == KEY_ROT_YM || \
	keycode == KEY_ROT_ZP || keycode == KEY_ROT_ZM)
		type = Rotate;
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		type = Zoom;
	else if (keycode == KEY_F)
		type = Free;
	else if (keycode == ESC)
		type = Exit;
	else
		type = Noset;
	return (type);
}