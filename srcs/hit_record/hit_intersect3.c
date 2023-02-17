/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:52:50 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/17 23:42:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_vec	_find_hit_normal_cn(const t_vec p, const t_vec center, \
const t_vec normal, const double cosine)
{
	const t_vec	cp = vec_sub(p, center);
	const t_vec	cp_prime = vec_mul(vec_unit(cp), cosine);

	return (vec_unit(vec_sub(cp_prime, normal)));
}

// void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
// const t_ray ray)
// {
// 	const t_cylinder	*cylinder = (t_cylinder *)cur_obj->data;
// 	const t_vec			x = vec_sub(ray.dir, vec_mul(cylinder->nor_vector, \
// 	fabs(vec_dot(ray.dir, cylinder->nor_vector))));
// 	const t_vec			ac = vec_sub(ray.origin, cylinder->center);
// 	const t_vec			y = vec_sub(ac, vec_mul(cylinder->nor_vector, \
// 	fabs(vec_dot(ac, cylinder->nor_vector))));
// 	double				root[2];

// 	if (!solve_quadratic(vec_dot(x, x), vec_dot(x, y), vec_dot(y, y) - \
// 	pow(cylinder->radius, 2), root))
// 		return ;
// 	printf("%lf %lf\n", root[0], root[1]);
// 	if (!_find_cy_root_((t_cylinder *)cylinder, root, ray))
// 		return ;
// 	printf("hi?\n");
// 	cur_h_rec->t_near = root[0];
// 	cur_h_rec->is_hit = TRUE;
// 	cur_h_rec->contact_point = vec_add(ray.origin, \
// 	vec_mul(ray.dir, cur_h_rec->t_near));
// 	cur_h_rec->hit_normal = _find_hit_normal_cy(cur_h_rec->contact_point, \
// 	cylinder->center, cylinder->nor_vector);
// 	cur_h_rec->albedo = vec_copy(cylinder->color);
// 	cur_h_rec->obj_type = CYLINDER;
// }

// void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
// const t_ray ray)
// {
// 	const t_cylinder	*cy = (t_cylinder *)cur_obj->data;
// 	const 		t_vec	ca = vec_sub(ray.origin, cy->center);
// 	const 		t_vec	y = vec_sub(ca, vec_mul(cy->nor_vector, \
// 	fabs(vec_dot(ca, cy->nor_vector))));
// 	const 		t_vec 	x = vec_sub(ray.dir, vec_mul(cy->nor_vector, \
// 	fabs(vec_dot(ray.dir, cy->nor_vector))));
// 	double				root[2];

// 	if (!solve_quadratic(vec_dot(x, x), vec_dot(x, y), vec_dot(y, y) - \
// 	(cy->radius * cy->radius), root))
// 		return ;
// 	t_vec	p[2];
// 	p[0] = vec_add(ray.origin, vec_mul(ray.dir, root[0]));
// 	p[1] = vec_add(ray.origin, vec_mul(ray.dir, root[1]));
// 	double	dist[2];
// 	printf("%lf %lf\n", root[0], root[1]);
// 	dist[0] = vec_dot(vec_sub(p[0], cy->center), cy->nor_vector);
// 	dist[1] = vec_dot(vec_sub(p[1], cy->center), cy->nor_vector);
// 	if (dist[0] <= BIAS){
// 		if (dist[1] <= BIAS)
// 			return ;
// 		root[0] = root[1];
// 		dist[0] = dist[1];
// 		p[0] = p[1];
// 	}
// 	cur_h_rec->t_near = root[0];
// 	cur_h_rec->is_hit = TRUE;
// 	cur_h_rec->contact_point = vec_add(ray.origin, \
// 	vec_mul(ray.dir, cur_h_rec->t_near));
// 	cur_h_rec->hit_normal = vec_sub(vec_sub(p[0], cy->center), \
// 	vec_mul(cy->nor_vector, dist[0]));
// 	cur_h_rec->albedo = vec_copy(cy->color);
// 	cur_h_rec->obj_type = CYLINDER;
// }