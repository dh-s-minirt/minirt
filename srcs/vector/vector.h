/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:28:47 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 10:05:22 by hyunkyle         ###   ########.fr       */
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
t_vec	vec_add(t_vec *v1, t_vec *v2);
t_vec	vec_sub(t_vec *v1, t_vec *v2);
t_vec	vec_mul(t_vec *v1, double t);
t_vec	vec_div(t_vec *v1, double t);
double	vec_length(t_vec *vec);

#endif