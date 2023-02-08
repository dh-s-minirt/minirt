/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_intersect3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:52:50 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/08 21:04:12 by daegulee         ###   ########.fr       */
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
