/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:07:57 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/02 14:36:39 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "./vector/vector.h"
# include "./vector/ray.h"
# include "./color/color.h"
# include <stdlib.h>
# include <math.h>

# define PI 3.1415926535897932385
# define FOCAL_LENGTH 1.0
# define VIEWPORT_HEIGHT 2.0
# define CANVAS_WIDTH 500
# define CANVAS_HEIGHT 500

//image info

typedef struct s_node	t_node;

typedef enum t_data_type
{
	SPHERE = 0,
	PLANE,
	CYLINDER,
}	t_data_type;

struct s_node
{
	t_data_type	type;
	void		*data;
	t_node		*next;
};

typedef struct s_sphere
{
	t_vec	center;
	double	diameter;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plain
{
	t_vec	coordinates;
	t_vec	nor_vector;
	t_color	color;
}	t_plain;

typedef struct s_cylinder
{
	t_vec	coordinates;
	t_vec	nor_vector;
	double	diameter;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_camera
{
	t_vec	coordinates;
	t_vec	nor_vector;
	double	viewprot_width;
	double	viewprot_height;
	double	focal_length;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	lower_left_corner;
	int		fov;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_light
{
	t_vec	coordinates;
	double	ratio;
	t_color	color;
}	t_light;

typedef struct s_info_data
{
	t_color			am_light;
	t_camera		camera;
	t_light			light;
	t_node			*shape;
	t_canvas		canvas;
	t_ray			ray;
}	t_info_data;

void		node_add_back(t_node **lst, t_node *new_node);
t_node		*node_new(void *data, t_data_type type);
t_canvas	canvas_new(int width, int height);

#endif
