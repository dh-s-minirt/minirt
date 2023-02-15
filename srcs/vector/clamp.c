/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:53:17 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/15 11:54:50 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "../math/math.h"

t_vec	copy_clamp(t_vec origin, double lower_bound, double upper_bound)
{
	t_vec	tmp;

	tmp.x = clamp(origin.x, lower_bound, upper_bound);
	tmp.y = clamp(origin.y, lower_bound, upper_bound);
	tmp.z = clamp(origin.z, lower_bound, upper_bound);
	return (tmp);
}

t_vec	copy_vec_clamp(t_vec origin, t_vec lower, t_vec upper)
{
	t_vec	tmp;

	tmp.x = clamp(origin.x, lower.x, upper.x);
	tmp.y = clamp(origin.y, lower.y, upper.y);
	tmp.z = clamp(origin.z, lower.z, upper.z);
	return (tmp);
}
