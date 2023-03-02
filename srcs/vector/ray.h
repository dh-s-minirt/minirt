/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:21:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/09 16:18:22 by hyunkyu          ###   ########.fr       */
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
t_ray	ray(t_vec orig, t_vec dir);

#endif