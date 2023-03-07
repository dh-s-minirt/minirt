/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:20:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/07 13:37:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdio.h>
# include <math.h>
# include "../vector/vector.h"
# include "../settings/setting.h"
# include "../Matrix/matrix.h"
# include "../mini_rt.h"
# include "../libft/libft.h"
# include "../hit_record/hit_record.h"
# include "../mini_rt.h"
# include "../mlx/mlx.h"

# define X 0
# define Y 1
# define DEFAULT_R 25

//put_img
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
t_my_mlx	init_mlx(void);
int			write_color(int t, t_vec pixel_color);
//render
void		init_property(t_hit_rec *hit_rec);
t_color		ray_casting(t_ray r, t_info_data *data, int depth);
void		*render(void *source_zip);
void		put_color(t_color pixel_color, int row, int col, t_mlx_data *data);

//shade
t_color		_shade_kphong(t_hit_rec hit_rec, t_info_data *data, \
t_phong_propety *property, t_ray ray);
t_color		_shade_reflect(t_hit_rec hit_rec, t_info_data *data, int depth, \
t_ray ray);
t_color		_shade_refract(t_hit_rec hit_rec, t_info_data *data, \
t_ray ray, t_fres_data fres_dat);
t_bool		check_shadow(t_node	*objects, t_hit_rec	*hit_rec, t_vec dir, \
t_lt_info cur_l_info);
t_lt_info	get_lt_info(t_light_node *light, t_hit_rec hit_rec);
t_color		_shade_uv(t_hit_rec hit_rec, t_info_data *data, t_ray r);
void		get_uv(t_hit_rec *cur_h_rec, double plane_scale, int is_check);
double		modulo(double x);
void		_check_pattern_(t_hit_rec *cur_h_rec, double check_n);
t_color		_shade_special(t_hit_rec hit_rec, t_info_data *data, t_ray r);
void		cone_mapping(t_hit_rec *cur_h_rec);
void		cy_mapping(t_hit_rec *cur_h_rec);
void		disk_mapping(t_hit_rec *cur_h_rec, int is_check);
void		planar_mapping(t_hit_rec *cur_h_rec, double scale);
void		spherical_mapping(t_hit_rec *cur_h_rec);
void		multi_thread(t_settings set, t_info_data *data, \
t_my_mlx *my_mlx);
t_zip		*_make_zip(t_settings set, \
t_info_data *data, \
t_my_mlx	*mlx, \
int row);
void		get_normal_map(t_hit_rec *hit_rec, t_ppm *normal_pp);

#endif
