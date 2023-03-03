/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:07:57 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 14:48:01 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "./vector/vector.h"
# include "./vector/ray.h"
# include "./color/color.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "./struct.h"

# define PI 3.1415926535897932385
# define TRUE 1
# define FALSE 0
# define THREAD_N 24

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef int				t_bool;
typedef struct s_node	t_node;

//image info
void			node_add_back(t_node **lst, t_node *new_node);
t_node			*node_new(void *data, t_obj_type type);
t_canvas		canvas_new(int width, int height);
t_light_node	*new_light_node(void *data, t_light_type type);
void			light_node_add_back(t_light_node **head, \
t_light_node *new_node);
t_ray			ray_primary(t_camera cam, double u, double v);
#endif
