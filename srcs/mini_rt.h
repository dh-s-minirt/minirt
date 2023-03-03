/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:07:57 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/18 15:41:58 by daegulee         ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

typedef int				t_bool;
typedef struct s_node	t_node;

typedef enum t_obj_type
{
	SPHERE = 0,
	PLANE,
	CYLINDER,
	CONE,
	DISK
}	t_obj_type;

typedef enum t_light_type
{
	AM_LIGHT = 0,
	LIGHT
}	t_light_type;

struct s_node
{
	t_obj_type	type;
	void		*data;
	t_node		*next;
};

typedef struct s_disk
{
	t_vec	center;
	double	r;
	t_color	color;
	t_vec	nor_v;
}	t_disk;

typedef struct s_sphere
{
	t_vec	center;
	double	diameter;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec	center;
	t_vec	nor_vector;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	center;
	t_vec	nor_vector;
	double	diameter;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_camera
{
	t_vec	center;
	t_vec	nor_vector;
	double	fov;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_cone
{
	double	radius;
	t_color	color;
	double	height;
	double	theta;
	t_vec	center;
	t_vec	nor_vector;
}	t_cone;

typedef struct s_light
{
	t_vec	center;
	double	ratio;
	t_color	color;
}	t_light;

typedef struct s_am_light
{
	t_color	color;
}	t_am_light;

typedef struct s_light_node
{
	void				*data;
	t_light_type		type;
	struct s_light_node	*next;
}	t_light_node;

typedef struct s_info_data
{
	t_camera		camera;
	t_node			*objects;
	t_light_node	*lights;
}	t_info_data;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct s_my_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_data	img;
}	t_my_mlx;

void			node_add_back(t_node **lst, t_node *new_node);
t_node			*node_new(void *data, t_obj_type type);
t_canvas		canvas_new(int width, int height);
t_light_node	*new_light_node(void *data, t_light_type type);
void			light_node_add_back(t_light_node **head, \
					t_light_node *new_node);
t_ray			ray_primary(t_camera cam, double u, double v);

#endif