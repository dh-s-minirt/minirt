/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:28:47 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/13 15:39:30 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include<math.h>

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

t_vec	vec(double x, double y, double z);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v1, double t);
t_vec	vec_div(t_vec v1, double t);
double	vec_length(t_vec vec);
double	length_squared(t_vec vec);
t_vec	vec_unit(t_vec v);
t_vec	vec_cross(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_less(t_vec vec1, t_vec vec2);
t_vec	vec_product(t_vec a, t_vec b);
t_vec	v_reflect(t_vec i, t_vec n);
t_vec	copy_clamp(t_vec origin, double lower_bound, double upper_bound);

#endif