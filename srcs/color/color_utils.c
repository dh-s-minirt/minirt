/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:50:43 by hyunkyu           #+#    #+#             */
/*   Updated: 2022/12/28 16:14:59 by hyunkyle         ###   ########.fr       */
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
