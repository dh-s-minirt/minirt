/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:46:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 16:55:30 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

typedef void				(*t_inersect_)(t_node *, t_hit_rec *, const t_ray);

static const t_inersect_	g_intersect[6] = {
	_intersect_sphere_, _intersect_plane_, _intersect_cylinder_, \
	_intersect_cone_, _intersect_disk_, NULL
};

t_abc	_make_abc_(const t_cone *cone, t_vec co, const t_ray ray)
{
	t_abc			tmp;
	const double	square_cos = pow(cos(degrees_to_radians(cone->theta)), 2);
	const double	dot_d_v = vec_dot(ray.dir, cone->nor_vector);
	const double	dot_co_v = vec_dot(co, cone->nor_vector);

	tmp.a = pow(dot_d_v, 2) - square_cos;
	tmp.b = 2 * ((dot_d_v) * dot_co_v - vec_dot(ray.dir, \
	vec_mul(co, square_cos)));
	tmp.c = pow(dot_co_v, 2) - vec_dot(co, co) * square_cos;
	return (tmp);
}

t_bool	_find_cone_root_(t_cone *cone, \
double root[2], const t_ray ray)
{	
	t_vec	cp[2];
	double	ans[2];

	cp[0] = vec_sub(vec_add(ray.origin, vec_mul(ray.dir, root[0])), \
	cone->center);
	cp[1] = vec_sub(vec_add(ray.origin, vec_mul(ray.dir, root[1])), \
	cone->center);
	ans[0] = vec_dot(cp[0], cone->nor_vector);
	ans[1] = vec_dot(cp[1], cone->nor_vector);
	if (ans[0] >= BIAS && ans[0] <= cone->height)
		return (TRUE);
	if (ans[1] >= BIAS && ans[1] <= cone->height)
	{
		root[0] = root[1];
		return (TRUE);
	}
	return (FALSE);
}

t_bool	query_hit(t_node *cur_obj, t_hit_rec *cur_h_rec, const t_ray ray)
{
	g_intersect[cur_obj->type](cur_obj, cur_h_rec, ray);
	cur_h_rec->object = cur_obj->data;
	return (cur_h_rec->is_hit);
}

t_vec	_find_hit_normal_cy(const t_vec p, const t_vec center, \
const t_vec normal)
{
	t_vec		hit_normal;
	const t_vec	cp = vec_sub(p, center);
	const t_vec	cx = vec_mul(normal, fabs(vec_dot(cp, normal)));

	hit_normal = vec_unit(vec_sub(cp, cx));
	return (hit_normal);
}
