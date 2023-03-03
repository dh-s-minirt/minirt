/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:27:32 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 14:44:54 by daegulee         ###   ########.fr       */
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

t_settings	_init_setting_(t_camera camera);
t_mat4		_camera_to_world_(t_vec normal);

#endif