/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:46:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 00:27:27 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

//cone -> radius, rgb Color, height, theta(0 ~ 180), center, normal vector, 
// identifier: Cn
//p = o+td;
// cone -> v,center,theta;
//function pointer void (*typedef name)
//typedef return_type      (*(notice <-function pointer) identifier)\
// (argument_type1...)         void (*)(t_node*,t_hit_rec*,t_ray)의 typedef가 t_~
typedef void				(*t_inersect_)(t_node *, t_hit_rec *, const t_ray);
//c언어 파싱 -> 일단 반환형 집어서 void -> identifier 괄호 있으니까 오른쪽 보고 다시 중간에 식별자
// *보고 포인터의 식별자인걸 알고 오른쪽으로가서 왼쪽 괄호보고 이게 함수의 식별자인걸 암  
//static const (function_pointer type)
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
	if (cur_obj->material.m_type == UV)
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
