/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:47:22 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/23 23:11:26 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./math.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

double	fmax_d(double x, double y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

