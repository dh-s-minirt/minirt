/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:50:43 by hyunkyu           #+#    #+#             */
/*   Updated: 2022/12/28 09:56:09 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	write_color(int t, t_color *pixel_color)
{
	return (t << 24 | (255 * pixel_color->r) << 16 | \
		(255 * pixel_color->g) << 8 | (255 * pixel_color->b));
}

t_color	color(int r, int g, int b)
{
	t_color	out;

	out.r = r;
	out.g = g;
	out.b = b;
	return (out);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
