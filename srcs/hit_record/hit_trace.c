/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:56:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/20 17:07:58 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"
#include <string.h>

t_hit_rec	_init_rec_(void)
{
	t_hit_rec	tmp;

	memset(&tmp, 0, sizeof(t_hit_rec));
	tmp.t_near = INFINITY;
	tmp.is_hit = FALSE;
	return (tmp);
}

void	_update_rec_(t_hit_rec *origin, t_hit_rec source)
{
	origin->contact_point = vec_copy(source.contact_point);
	origin->hit_normal = vec_copy(source.hit_normal);
	origin->is_hit = source.is_hit;
	origin->t_near = source.t_near;
	origin->albedo = vec_copy(source.albedo);
	origin->obj_type = source.obj_type;
}

t_bool	trace_hit(t_node	*objects, t_hit_rec	*hit_rec, t_ray ray)
{
	t_node		*cur_object;
	t_hit_rec	cur_hit_rec;

	cur_object = objects;
	while (cur_object)
	{
		cur_hit_rec = _init_rec_();
		if (query_hit(cur_object, &cur_hit_rec, ray))
		{
			if (hit_rec->t_near == INFINITY || \
			cur_hit_rec.t_near < hit_rec->t_near)
				_update_rec_(hit_rec, cur_hit_rec);
		}
		cur_object = cur_object->next;
	}
	return (hit_rec->is_hit);
}
