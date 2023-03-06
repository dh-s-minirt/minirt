/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:47:22 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 15:40:19 by idaegyu          ###   ########.fr       */
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

double	circle_clamp(double x, double min, double max)
{
	if (x < min)
		return (max - (x - min));
	if (x > max)
		return (x - max);
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

