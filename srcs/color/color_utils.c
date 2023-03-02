/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:50:43 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/03/02 12:54:20 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	fmax(double d1, double d2)
{
	if (d1 > d2)
		return (d1);
	return (d2);
}

double	ft_powf(double d, double n)
{
	double	result;

	result = 1;
	while (n > 0)
	{
		result *= d;
		n--;
	}
	return (result);
}
