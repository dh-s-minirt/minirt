/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:27:32 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 23:36:10 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# include <math.h>
# include "../vector/vector.h"
# include "../Matrix/matrix.h"
# include "../math/math.h"
# include "../mini_rt.h"
# include "../color/color.h"

# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 720

typedef struct s_settings{
	double	fov;
	int		screen_width;
	int		screen_height;
	double	aspect_ratio;
	t_mat4	camera_to_world;
	double	bias;
	double	scale;
}	t_settings;

t_settings	_init_setting_(t_info_data data);
t_mat4		_camera_to_world_(t_vec normal);

#endif