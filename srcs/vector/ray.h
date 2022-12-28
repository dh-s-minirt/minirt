/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:21:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 10:52:28 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

/*
orig = 원점 좌표
dir	 = 방향 벡터
*/
typedef struct s_ray
{
	t_vec	origin;
	t_vec	dir;
}	t_ray;

t_vec	ray_at(t_ray *ray, double t);

#endif