/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:20:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/23 14:51:11 by daegulee         ###   ########.fr       */
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

# define DEFAULT_R 30

typedef struct s_lt_info
{
	t_vec	dir;
	t_vec	intensity;
	double	dist;
}	t_lt_info;

//put_img
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
t_my_mlx	init_mlx(void);
int			write_color(int t, t_vec pixel_color);
//render
void		init_property(t_hit_rec *hit_rec);
t_color		ray_casting(t_ray r, t_info_data *data, int depth);
void		render(t_settings set, t_info_data	*data, t_my_mlx *mlx);
void		put_color(t_color pixel_color, int row, int col, t_mlx_data *data);

//shade
t_color		_shade_kphong(t_hit_rec hit_rec, t_info_data *data, \
t_phong_propety *property, t_ray ray);
t_bool		check_shadow(t_node	*objects, t_hit_rec	*hit_rec, t_vec dir, \
t_lt_info cur_l_info);
t_lt_info	get_lt_info(t_light_node *light, t_hit_rec hit_rec);

#endif
