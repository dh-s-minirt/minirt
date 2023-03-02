/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:42:23 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/02/07 16:46:17 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../vector/vector.h"
# define EPSILON 1e-6
# define LUMEN 3

typedef t_vec		t_color;

struct s_dummy_color
{
	t_color	diffuse;
	t_vec	light_dir;
	double	kd;
	t_color	specular;
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;
	double	ksn;
	double	ks;
	double	brightness;
};

int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		create_trgb(int t, int r, int g, int b);
double	fmax(double d1, double d2);
double	ft_powf(double d, double n);

#endif