/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:49:23 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/09 23:40:52 by daegulee         ###   ########.fr       */
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

typedef enum t_material
{
	Kphong = 0,
	Kfresnel,
	Uv,
	Special,
	Kdiffuse
}	t_material;

typedef struct s_phong_propety
{
	double	kd;
	double	ks;
	double	n;
}	t_phong_propety;

typedef struct s_fresenel_property
{
	double	ior;
	double	kr;
}	t_fres_property;

// typedef struct s_check_property
// {

// }	t_check_property;

// typedef struct s_special_property
// {

// }	t_special_property;

typedef struct s_hit_rec
{
	double		t_near;
	t_vec		hit_normal;
	void		*property;
	t_material	material;
	t_vec		contact_point;
	t_bool		is_hit;
	t_color		albedo;
}	t_hit_rec;

//1
t_bool	solve_quadratic(const double a, const double half_b, const double c, \
double root[2]);
void	_intersect_sphere_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
t_bool	_find_cy_root_(t_hit_rec *cur_h_rec, t_cylinder *cylinder, \
double root[2], const t_ray ray);
void	_intersect_cylinder_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
void	_intersect_plane_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);
t_bool	trace_hit(t_node	*objects, t_hit_rec	*hit_rec, t_ray ray);

//2
t_bool	query_hit(t_node *cur_obj, t_hit_rec *cur_h_rec, const t_ray ray);
void	_intersect_cone_(t_node *cur_obj, t_hit_rec *cur_h_rec, \
const t_ray ray);

t_vec	_find_hit_normal_cy(const t_vec p, const t_vec center, \
const t_vec normal);
t_vec	_find_hit_normal_cn(const t_vec p, const t_vec center, \
const t_vec normal, const double cosine);
t_color	_shade_kphong(t_hit_rec hit_rec, t_info_data *data, \
t_phong_propety *property);

#endif