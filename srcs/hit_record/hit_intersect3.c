/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:52:50 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/25 23:17:34 by daegulee         ###   ########.fr       */
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
	cur_h_rec->hit_center = vec_copy(disk->center);
}
