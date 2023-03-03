/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:49:23 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 14:46:41 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include <math.h>
# include "../vector/vector.h"
# include "../settings/setting.h"
# include "../Matrix/matrix.h"
# include "../mini_rt.h"
# include "../libft/libft.h"
# include <stdio.h>

//1
t_bool		solve_quadratic(const double a, const double half_b, \
const double c, double root[2]);
void		_intersect_sphere_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
t_bool		_find_cone_root_(t_cone *cone, \
double root[2], const t_ray ray);
void		_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
void		_intersect_plane_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
t_bool		trace_hit(t_node	*objects, t_hit_rec	*hit_rec, t_ray ray);
t_hit_rec	_init_rec_(void);

//2
t_abc		_make_abc_(const t_cone *cone, t_vec co, const t_ray ray);
t_bool		query_hit(t_node *cur_obj, t_hit_rec *cur_h_rec, const t_ray ray);
void		_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
void		_intersect_disk_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
t_vec		_find_hit_normal_cy(const t_vec p, const t_vec center, \
const t_vec normal);
t_vec		_find_hit_normal_cn(const t_vec p, const t_vec center, \
const t_vec normal, const double cosine);
#endif