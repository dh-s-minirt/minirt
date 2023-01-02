/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:50:43 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/01/02 11:42:45 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	write_color(int t, t_vec *pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color->x) << 16 | \
		(int)(255 * pixel_color->y) << 8 | (int)(255 * pixel_color->z));
}

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

double	powf(double d, double n)
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
