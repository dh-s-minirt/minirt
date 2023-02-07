/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:56:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 16:06:30 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_hit_rec	_init_rec_(void)
{
	t_hit_rec	tmp;

	tmp.t_near = INFINITY;
	tmp.is_hit = FALSE;
	return (tmp);
}

void	_swap_rec_(t_hit_rec *origin, t_hit_rec source)
{
	origin->contact_point = source.contact_point;
	// origin->hit_normal = source.contact_point;
	origin->is_hit = source.is_hit;
	origin->t_near = source.t_near;
}

t_bool	trace_hit(t_node	*objects, t_hit_rec	*hit_rec, t_ray ray)
{
	double		cur_t_near;
	t_node		*cur_object;
	t_hit_rec	cur_hit_rec;

	cur_object = objects;
	while (cur_object)
	{
		cur_hit_rec = _init_rec_();
		if (query_hit(cur_object, &cur_hit_rec, ray) && cur_hit_rec.t_near < \
		hit_rec->t_near)
			_swap_rec_(hit_rec, cur_hit_rec);
	}
	return (hit_rec->is_hit);
}
