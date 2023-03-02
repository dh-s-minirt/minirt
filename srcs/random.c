/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:50:02 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/02/07 17:47:10 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

double	randv(void)
{
	static int	seed;

	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return ((double)seed / (double)0x80000000);
}

t_vec	random_vec(void)
{
	return (vec(randv(), randv(), randv()));
}
