/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:50:07 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 00:31:08 by daegulee         ###   ########.fr       */
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
