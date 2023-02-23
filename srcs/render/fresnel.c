/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:18:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/21 20:34:53 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>
#include "../color/color.h"

void	_swap_(double	*a, double	*b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//T = nI+(c1-nc2); c1 = abs(cos1) * n
// T = eta * I+(eta*cos1-c2)*n  
t_vec	refract(t_vec i, t_vec n, double ior)
{
	double	etai;
	double	etat;
	double	c2;
	double	cos1;
	double	eta;

	etai = 1.0;
	etat = ior;
	cos1 = vec_dot(n, i);
	if (cos1 < 0)
		cos1 = -cos1;
	else
	{
		n = vec_mul(n, -1);
		_swap_(&etai, &etat);
	}
	eta = etai / etat;
	c2 = 1 - pow(eta, 2) * (1 - pow(cos1, 2));
	if (c2 < 0)
		return (vec(0, 0, 0));
	else
		return (vec_add(vec_mul(i, eta), \
		vec_mul(n, eta * cos1 - sqrt(c2))));
}