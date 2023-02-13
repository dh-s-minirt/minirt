/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:56:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 01:38:41 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_hit_rec	_init_rec_(void)
{
	t_hit_rec	tmp;

	ft_memset(&tmp, 0, sizeof(t_hit_rec));
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
			// printf("cur : %lf prev : %lf \n", cur_hit_rec.t_near, \
			// hit_rec->t_near);
			if (hit_rec->t_near == INFINITY || \
			cur_hit_rec.t_near < hit_rec->t_near)
				_update_rec_(hit_rec, cur_hit_rec);
		}
		cur_object = cur_object->next;
	}
	return (hit_rec->is_hit);
}
