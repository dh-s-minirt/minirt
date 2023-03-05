/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:43:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 02:46:25 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

# include "../mlx/mlx.h"
# include "../settings/setting.h"

# define KEY_C 8
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_C 8
# define KEY_F 3
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_ROT_XP 43
# define KEY_ROT_XM 47
# define KEY_ROT_YP 40
# define KEY_ROT_YM 37
# define KEY_ROT_ZP 34
# define KEY_ROT_ZM 35
# define X_KEY_EXIT 17
# define CMODE 0
# define OMODE 1
# define TITLE_WIDTH 400
# define TITLE_HIGHT 200

void		draw_line(t_point p1, t_point p2, t_mlx_data *data);
void		draw_frame(t_mlx_data *data);
void		draw_title(t_my_mlx *my_mlx);
void		draw_xpm(t_my_mlx *my_mlx, char *xpm, int x, int y);
void		draw_sidebar(t_my_mlx *my_mlx);
void		draw_topbar(t_my_mlx *my_mlx, t_m_dat mdat);
void		obj_update_r_center(t_zip *zip, char mode, double theta);
void		rotate_up_c_x(t_zip *zip, double theta);
void		rotate_up_nor_x(t_zip *zip, double theta);
void		rotate_up_c_y(t_zip *zip, double theta);
void		rotate_up_nor_y(t_zip *zip, double theta);
void		rotate_up_c_z(t_zip *zip, double theta);
void		rotate_up_nor_z(t_zip *zip, double theta);
void		rotate_up_x(t_zip *zip, double theta);
void		rotate_up_y(t_zip *zip, double theta);
void		rotate_up_z(t_zip *zip, double theta);
t_vec		*get_center(void *obj, t_obj_type type);
t_vec		*get_normal(void *obj, t_obj_type type);
t_key_type	get_key(int keycode);
void		update_center(t_zip *zip, char mode, long double e);
void		update_center_z(t_zip *zip, long double e);
void		update_center_y(t_zip *zip, long double e);
void		update_center_x(t_zip *zip, long double e);
void		start_draw(t_zip *zip);
void		change_mode(t_zip *zip);
void		change_select(t_zip *zip);
void		object_picking(int x, int y, t_zip *zip);
int			key_hook(int keycode, t_zip *zip);
int			mouse_hook(int button, int x, int y, t_zip *zip);
void		my_hook(t_zip *zip);
void		object_move(t_zip *zip, int keycode);
void		camera_move(t_zip *zip, int keycode);
void		zoom(t_zip *zip, int keycode);
void		move(t_zip *zip, int keycode);

#endif