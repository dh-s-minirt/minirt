/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:42:31 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 10:27:25 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_bool	solve_quadratic(const double a, const double half_b, const double c, \
t_hit_rec *cur_h_rec)
{
	const double	discriminant = half_b * half_b - a * c;
	double			root1;
	double			root2;

	if (discriminant < 0)
		return (FALSE);
	else if (discriminant == 0)
		cur_h_rec->t_near = (-half_b) / a;
	else
	{
		root1 = (-half_b - sqrt(discriminant)) / a;
		root2 = (-half_b + sqrt(discriminant)) / a;
		if (root1 < 0)
		{
			if (root2 < 0)
				return (FALSE);
			root1 = root2;
		}
		cur_h_rec->t_near = root1;
	}
	return (TRUE);
}

void	_intersect_sphere_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_sphere	*sphere = (t_sphere *)cur_obj->data;
	const double	a = vec_dot(ray.dir, ray.dir);
	const t_vec		ac = vec_sub(ray.origin, sphere->center);
	const double	half_b = vec_dot(ac, ray.dir);
	const double	c = vec_dot(ac, ac) - (sphere->radius * sphere->radius);

	if (solve_quadratic(a, half_b, c, cur_h_rec))
		cur_h_rec->is_hit = TRUE;
}

void	_intersect_plane_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);

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