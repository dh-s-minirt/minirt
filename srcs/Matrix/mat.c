/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:14:30 by daegulee          #+#    #+#             */
/*   Updated: 2023/01/30 20:34:23 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"

t_mat4	_init_mat_(int mode)
{
	int		i;
	int		j;
	t_mat4	tmp;

	i = -1;
	if (mode == DEFAULT)
		ft_memset(&tmp, 0, sizeof(tmp));
	else
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (i == j)
					tmp.m[i][j] = 1;
				else
					tmp.m[i][j] = 0;
			}
		}	
	}
	return (tmp);
}

t_mat4	_make_cord_(double xyz[3][3])
{
	int		i;
	int		j;
	t_mat4	tmp;

	i = -1;
	tmp = _init_mat_(DEFAULT);
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			tmp.m[i][j] = xyz[i][j];
	}
	tmp.m[3][3] = 1;
	return (tmp);
}

t_mat4	_mul_mat_(const t_mat4 a, const t_mat4 b)
{
	t_mat4	mul;
	int		i;
	int		j;
	int		k;

	i = -1;;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			mul.m[i][j] = 0;
			while (++k < 4)
			{
				mul.m[i][j] += a.m[i][k] * b.m[k][j];
			}		
		}
	}
	return (mul);
}
//전치행렬 구하기

t_mat4	_transpose_mat_(const t_mat4 a)
{
	t_mat4	transpose;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			transpose.m[i][j] = a.m[j][i];
		}
	}
	return (transpose);
}

t_mat4	_inverse_mat_(const t_mat4 a, int mode)
{
	t_mat4	inverse;

	if (mode == ORTHO)
		return (_transpose_mat_(a));
	// 일반적인 케이스에 역행렬 필요하면 구현.
	return (_init_mat_(DEFAULT));
}
