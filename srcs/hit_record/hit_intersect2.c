/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:46:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/17 17:58:29 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

//cone -> radius, rgb Color, height, theta(0 ~ 180), center, normal vector, 
// identifier: Cn
//p = o+td;
// cone -> v,center,theta;
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


void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cone	*cone = (t_cone *)cur_obj->data;
	const t_vec		co = vec_sub(ray.origin, cone->center);
	double			root[2];
	const t_abc		abc = _make_abc_((const t_cone *)cone, co, ray);

	if (!solve_quadratic(abc.a, abc.b, abc.c, root))
		return ;
	if (!_find_cone_root_((t_cone *)cone, root, ray))
		return ;
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = _find_hit_normal_cn(cur_h_rec->contact_point, \
	cone->center, cone->nor_vector, cos(degrees_to_radians(cone->theta)));
	cur_h_rec->albedo = vec_copy(cone->color);
	cur_h_rec->obj_type = CONE;
	// printf("color r %lf: g %lf: b %lf:\n", \
	// cone->color.x, cone->color.x,cone->color.x);
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

t_vec	_find_hit_normal_cy(const t_vec p, const t_vec center, \
const t_vec normal)
{
	t_vec		hit_normal;
	const t_vec	cp = vec_sub(p, center);
	const t_vec	cx = vec_mul(normal, fabs(vec_dot(cp, normal)));

	hit_normal = vec_unit(vec_sub(cp, cx));
	return (hit_normal);
}
