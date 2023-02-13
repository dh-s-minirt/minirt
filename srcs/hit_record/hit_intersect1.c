/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:42:31 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 01:44:51 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_bool	solve_quadratic(const double a, const double half_b, const double c, \
double root[2])
{
	const double	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	else if (discriminant == 0)
	{
		root[0] = (-half_b) / a;
		root[1] = root[0];
	}
	else
	{
		root[0] = (-half_b - sqrt(discriminant)) / a;
		root[1] = (-half_b + sqrt(discriminant)) / a;
		if (root[0] <= BIAS)
		{
			if (root[1] <= BIAS)
				return (FALSE);
			root[0] = root[1];
		}
	}
	return (TRUE);
}

void	_intersect_sphere_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_sphere	*sphere = (t_sphere *)cur_obj->data;
	const t_vec		ac = vec_sub(ray.origin, sphere->center);
	double			root[2];

	if (!solve_quadratic(vec_dot(ray.dir, ray.dir), vec_dot(ac, ray.dir), \
	vec_dot(ac, ac) - pow(sphere->radius, 2), root))
		return ;
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = vec_unit(vec_sub(cur_h_rec->contact_point, \
	sphere->center));
	cur_h_rec->albedo = vec_copy(sphere->color);
	// printf("sphere color r %lf: g %lf: b %lf:\n", \
	// sphere->color.x, sphere->color.y,sphere->color.z);
}

void	_intersect_plane_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_plane	*plane = (t_plane *)cur_obj->data;
	const double	devider = vec_dot(ray.dir, plane->nor_vector);
	double			root;
	const t_vec		ca = vec_sub(plane->center, ray.origin);

	if (devider == 0)
		return ;
	root = vec_dot(ca, plane->nor_vector) / devider;
	if (root <= BIAS)
		return ;
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->t_near = root;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	if (vec_dot(plane->nor_vector, vec_sub(cur_h_rec->\
	contact_point, ray.origin)) < 0)
		cur_h_rec->hit_normal = vec_unit(plane->nor_vector);
	else
		cur_h_rec->hit_normal = vec_unit(vec_mul(plane->nor_vector, -1));
	cur_h_rec->albedo = vec_copy(plane->color);
	// printf("plane color r %lf: g %lf: b %lf:\n", \
	// plane->color.x, plane->color.y,plane->color.z);
}

t_bool	_find_cy_root_(t_cylinder *cylinder, \
double root[2], const t_ray ray)
{	
	t_vec	cp[2];
	double	ans[2];

	cp[0] = vec_sub(vec_add(ray.origin, vec_mul(ray.dir, root[0])), \
	cylinder->center);
	cp[1] = vec_sub(vec_add(ray.origin, vec_mul(ray.dir, root[1])), \
	cylinder->center);
	ans[0] = vec_dot(cp[0], cylinder->nor_vector);
	ans[1] = vec_dot(cp[1], cylinder->nor_vector);
	if (ans[0] >= BIAS && ans[0] <= cylinder->height)
		return (TRUE);
	if (ans[1] >= BIAS && ans[1] <= cylinder->height)
	{
		root[0] = root[1];
		return (TRUE);
	}
	return (FALSE);
}

void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cylinder	*cylinder = (t_cylinder *)cur_obj->data;
	const t_vec			x = vec_sub(ray.dir, vec_mul(cylinder->nor_vector, \
	fabs(vec_dot(ray.dir, cylinder->nor_vector))));
	const t_vec			ac = vec_sub(ray.origin, cylinder->center);
	const t_vec			y = vec_sub(ac, vec_mul(cylinder->nor_vector, \
	fabs(vec_dot(ac, cylinder->nor_vector))));
	double				root[2];

	if (!solve_quadratic(vec_dot(x, x), vec_dot(x, y), vec_dot(y, y) - \
	pow(cylinder->radius, 2), root))
		return ;
	if (!_find_cy_root_((t_cylinder *)cylinder, root, ray))
		return ;
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = _find_hit_normal_cy(cur_h_rec->contact_point, \
	cylinder->center, cylinder->nor_vector);
	cur_h_rec->albedo = vec_copy(cylinder->color);
	// printf("cy color r %lf: g %lf: b %lf:\n", \
	// cur_h_rec->albedo.x, cur_h_rec->albedo.y,cur_h_rec->albedo.z);
}
