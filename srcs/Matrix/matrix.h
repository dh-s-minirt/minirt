/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:11:15 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/14 15:03:08 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include "../vector/vector.h"
# define DEFAULT 0
# define I 1
# define ORTHO 0 //직교
# define NORMAL 1

typedef struct s_mat4{
	double	m[4][4];
}	t_mat4;

typedef struct s_arr_vec3{
	double	v[3];
}	t_arr_vec3;
//mat
t_mat4		_init_mat_(int mode);
t_mat4		_mul_mat_(const t_mat4 a, const t_mat4 b);
t_mat4		_transpose_mat_(const t_mat4 a);
t_mat4		_inverse_mat_(const t_mat4 a, int mode);
//rotate
t_mat4		_rotate_mat_(const double theta, char mode);

//transform
t_vec		_mul_vec_mat(const t_mat4 a, t_arr_vec3	arr_vec);

//arr_vec
t_mat4	_make_mat_with_vec(const t_vec	x_cord, const t_vec	y_cord, \
const t_vec	z_cord);
t_arr_vec3	vec_2_arr_vec3(t_vec vec);
t_vec		arr_vec3_2_vec(t_arr_vec3 vec3);

void	print_mat(const t_mat4 a);
t_mat4	_make_cord_(double xyz[3][3]);
void	print_mat(const t_mat4 a);

#endif