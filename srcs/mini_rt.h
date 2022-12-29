/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:07:57 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/29 11:20:21 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "./vector/vector.h"
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
	int		color_range;
}	t_sphere;

typedef struct s_plain
{
	t_vec	coordinates;
	t_vec	nor_vector;
	int		color_range;
}	t_plain;

typedef struct s_cylinder
{
	t_vec	coordinates;
	t_vec	nor_vector;
	double	diameter;
	double	height;
	int		color_range;
}	t_cylinder;

typedef struct s_am_lightning
{
	double	ratio_in_range;
	int		color_range;
}	t_am_lightning;

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
    int     width;
    int     height;
    double  aspect_ratio;
}	t_canvas;

typedef struct s_light
{
	t_vec	coordinates;
	double	ratio_in_range;
	int		color_range;
}	t_light;

typedef struct s_info_data
{
	t_am_lightning	am_light;
	t_camera		camera;
	t_light			light;
	t_node			*shape;
	t_canvas		canvas;
}	t_info_data;

void		node_add_back(t_node **lst, t_node *new);
t_node		*node_new(void *data, t_data_type type);
t_canvas	canvas_new(int width, int height);

#endif
