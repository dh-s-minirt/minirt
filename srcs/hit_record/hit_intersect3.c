/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:52:50 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/02 13:03:37 by daegulee         ###   ########.fr       */
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

void	_intersect_disk_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_disk	*disk = (t_disk *)cur_obj->data;
	const double	devider = vec_dot(ray.dir, disk->nor_v);
	double			root;
	const t_vec		ca = vec_sub(disk->center, ray.origin);

	if (devider == 0)
		return ;
	root = vec_dot(ca, disk->nor_v) / devider;
	if (root <= BIAS || \
	vec_length(vec_sub(disk->center, \
	vec_add(ray.origin, \
	vec_mul(ray.dir, root)))) > disk->r - BIAS)
		return ;
	cur_h_rec->t_near = root;
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	if (vec_dot(disk->nor_v, vec_sub(cur_h_rec->contact_point, ray.origin)) < 0)
		cur_h_rec->hit_normal = vec_unit(disk->nor_v);
	else
		cur_h_rec->hit_normal = vec_unit(vec_mul(disk->nor_v, -1));
	cur_h_rec->albedo = vec_copy(disk->color);
	cur_h_rec->obj_type = DISK;
	cur_h_rec->material = cur_obj->material;
}

void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray)
{
	const t_cone	*cn = (t_cone *)cur_obj->data;
	const t_vec		co = vec_sub(ray.origin, cn->center);
	const double	cos2 = cos(cn->theta) * cos(cn->theta);
	const double	half_b = vec_dot(ray.dir, cn->nor_vector) * \
	vec_dot(co, cn->nor_vector) - vec_dot(ray.dir, co) * cos2;
	double			root[2];

	if (!solve_quadratic(pow(vec_dot(ray.dir, cn->nor_vector), 2) - \
	cos2, half_b, pow(vec_dot(co, cn->nor_vector), 2) - \
	vec_dot(co, co) * cos2, root))
		return ;
	if (!_find_cone_root_((t_cone *)cn, root, ray))
		return ;
	cur_h_rec->t_near = root[0];
	cur_h_rec->is_hit = TRUE;
	cur_h_rec->contact_point = vec_add(ray.origin, \
	vec_mul(ray.dir, cur_h_rec->t_near));
	cur_h_rec->hit_normal = _find_hit_normal_cn(cur_h_rec->contact_point, \
	cn->center, cn->nor_vector, cos(cn->theta));
	cur_h_rec->albedo = vec_copy(cn->color);
	cur_h_rec->obj_type = CONE;
	cur_h_rec->material = cur_obj->material;
}
