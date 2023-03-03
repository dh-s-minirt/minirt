/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:43:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/04 01:14:44 by daegulee         ###   ########.fr       */
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
# define KEY_ROT_ZM 31
# define X_KEY_EXIT 17
# define CMODE 0
# define OMODE 1

void	draw_frame(t_mlx_data *data);
void	draw_title(t_my_mlx *my_mlx);
void	draw_xpm(t_my_mlx *my_mlx, char *xpm, int x, int y);
void	draw_sidebar(t_my_mlx *my_mlx);
void	draw_topbar(t_my_mlx *my_mlx, t_m_dat mdat);

#endif