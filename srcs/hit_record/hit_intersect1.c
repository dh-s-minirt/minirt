/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:42:31 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/24 18:55:43 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hit_record.h"

t_bool	solve_quadratic(const double a, const double half_b, const double c, \
double root[2])
{
	const double	discriminant = half_b * half_b - a * c;

	if (discriminant < 0 || (a <= BIAS && half_b <= BIAS))
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
	cur_h_rec->obj_type = SPHERE;
	cur_h_rec->material = cur_obj->material;
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
	cur_h_rec->obj_type = PLANE;
	cur_h_rec->material = cur_obj->material;
}

void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cylinder	*cy = (t_cylinder *)cur_obj->data;
	const t_vec			oc = vec_sub(ray.origin, cy->center);
	const double		a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, \
	cy->nor_vector), 2);
	const double		half_b = vec_dot(ray.dir, oc) - vec_dot(ray.dir, cy->nor_vector) * \
	vec_dot(oc, cy->nor_vector);
	const double		c = vec_dot(oc, oc) - pow(vec_dot(oc, cy->nor_vector), 2) - \
	pow(cy->radius, 2);
	double				root[2];

	if (!solve_quadratic(a, half_b, c, root))
		return ;
	// printf("%lf <-r \n", cy->radius);
	// printf("%lf %lf %lf\n", a,half_b,c);
	// printf("a %lf b %lf c  %lf root : %lf %lf\n", a,half_b,c,root[0], root[1]);
	t_vec	p[2];
	p[0] = vec_add(ray.origin, vec_mul(ray.dir, root[0]));
	p[1] = vec_add(ray.origin, vec_mul(ray.dir, root[1]));
	double	dist[2];
	dist[0] = vec_dot(vec_sub(p[0], cy->center), cy->nor_vector);
	dist[1] = vec_dot(vec_sub(p[1], cy->center), cy->nor_vector);
	if (dist[0] <= BIAS || dist[0] > cy->height + BIAS){
		if (dist[1] <= BIAS || dist[1] > cy->height + BIAS)
			return ;
		root[0] = root[1];
		dist[0] = dist[1];
		p[0] = p[1];
	}
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = _find_hit_normal_cy(cur_h_rec->contact_point, \
	cy->center, cy->nor_vector);
	cur_h_rec->albedo = vec_copy(cy->color);
	cur_h_rec->obj_type = CYLINDER;
	cur_h_rec->material = cur_obj->material;
}

void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cone	*cn = (t_cone *)cur_obj->data;
    const double cos2 = cos(cn->theta) * cos(cn->theta);
	const double	a = pow(vec_dot(ray.dir, cn->nor_vector), 2) - \
	cos2;
	const t_vec		co = vec_sub(ray.origin, cn->center);
	const double	half_b = vec_dot(ray.dir, cn->nor_vector) * \
	vec_dot(co, cn->nor_vector) - vec_dot(ray.dir, co) * cos2;
	const double	c = pow(vec_dot(co, cn->nor_vector), 2) - \
	vec_dot(co, co) * cos2;
	double			root[2];

	if (!solve_quadratic(a, half_b, c, root))
		return ;
	if (!_find_cone_root_((t_cone *)cn, root, ray))
		return ;
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = _find_hit_normal_cn(cur_h_rec->contact_point, \
	cn->center, cn->nor_vector, cos(cn->theta));
		// cur_h_rec->hit_normal = vec(0,0,0);
	cur_h_rec->albedo = vec_copy(cn->color);
	cur_h_rec->obj_type = CONE;
	cur_h_rec->material = cur_obj->material;
	// printf("color r %lf: g %lf: b %lf:\n", \
	// cone->color.x, cone->color.x,cone->color.x);
}
