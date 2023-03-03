/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:27:32 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 20:41:48 by idaegyu          ###   ########.fr       */
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

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

t_settings	_init_setting_(t_camera camera);
t_mat4		_camera_to_world_(t_vec normal);

#endif