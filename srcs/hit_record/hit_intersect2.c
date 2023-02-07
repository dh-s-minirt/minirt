/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:46:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 16:13:57 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

//cone -> radius, rgb Color, height, theta(0 ~ 180), center, normal vector, 
// identifier: Cn
void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cone	*cone = (t_cone *)cur_obj->data;
	const t_vec		co = vec_sub(ray.origin, cone->center);
	double			root[2];

//	x = o+td, c = v, theta;
	solve_quadratic((pow(vec_dot(ray.dir, cone->nor_vector), 2)), \
	2 * (vec_dot(ray.dir, cone->nor_vector) * )
}

t_bool	query_hit(t_node *cur_obj, t_hit_rec *cur_h_rec, const t_ray ray)
{
	if (cur_obj->type == SPHERE)
		_intersect_sphere_(cur_obj, cur_h_rec, ray);
	else if (cur_obj->type == PLANE)
		_intersect_plane_(cur_obj, cur_h_rec, ray);
	else if (cur_obj->type == CYLINDER)
		_intersect_cylinder_(cur_obj, cur_h_rec, ray);
	else
		_intersect_cone_(cur_obj, cur_h_rec, ray);
	return (cur_h_rec->is_hit);
}

