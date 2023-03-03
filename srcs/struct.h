/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:41:50 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/03 15:03:36 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./vector/vector.h"
# include "./vector/ray.h"
# include "./color/color.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "./Matrix/matrix.h"

typedef int					t_bool;
typedef struct s_node		t_node;
typedef struct s_material	t_material;
typedef enum e_obj_type		t_obj_type;
typedef struct s_camera		t_camera;
typedef struct s_info_data	t_info_data;
typedef struct s_my_mlx		t_my_mlx;
typedef struct s_camera		t_camera;

enum e_obj_type
{
	SPHERE = 0,
	PLANE,
	CYLINDER,
	CONE,
	DISK,
	MS
};

typedef struct s_camera
{
	t_vec	center;
	t_vec	nor_vector;
	double	fov;
}	t_camera;

typedef enum t_m_type
{
	REFLECT = 0,
	PHONG,
	FRESNEL,
	UV,
	SPECIAL
}	t_m_type;

struct s_material
{
	void		*property;
	t_m_type	m_type;
};


typedef struct s_fres_data
{
	double	ior;
	int		depth;
}	t_fres_data;

typedef struct s_lt_info
{
	t_vec	dir;
	t_vec	intensity;
	double	dist;
}	t_lt_info;

typedef struct s_abc
{
	double	a;
	double	b;
	double	c;
}	t_abc;

typedef struct s_settings{
	t_camera	camera;
	double		fov;
	int			screen_width;
	int			screen_height;
	double		aspect_ratio;
	t_mat4		camera_to_world;
	double		bias;
	double		scale;
}	t_settings;

typedef struct s_m_dat
{
	t_bool		mode;
	t_bool		choice_obj;
	void		*object;
	t_obj_type	obj_type;
}	t_m_dat;

typedef struct s_hit_rec
{
	double		t_near;
	t_vec		hit_normal;
	t_material	material;
	t_vec		contact_point;
	t_bool		is_hit;
	t_color		albedo;
	t_obj_type	obj_type;
	double		u;
	double		v;
	void		*object;
}	t_hit_rec;

typedef struct s_zip
{
	t_settings	set;
	t_info_data	*data;
	t_my_mlx	*mlx;
	int			start_row;
	t_m_dat		*mdat;
}	t_zip;

typedef struct s_ppm
{
	t_color	*map;
	int		width;
	int		height;
	int		max;
}	t_ppm;

typedef enum t_light_type
{
	AM_LIGHT = 0,
	LIGHT
}	t_light_type;

typedef enum t_special_type
{
	S1,
	S2,
	S3
}	t_special_type;

typedef enum t_mash_type
{
	M1,
	M2,
	M3
}	t_mash_type;

typedef struct s_phong_propety
{
	double	kd;
	double	ks;
	double	n;
}	t_phong_propety;

typedef struct s_fresenel_property
{
	double	ior;
}	t_fres_property;

typedef struct s_special_property
{
	char	*ppm_name;
	t_ppm	*ppm;
}	t_special_property;

struct s_node
{
	t_obj_type	type;
	t_material	material;
	void		*data;
	t_node		*next;
};

typedef struct s_disk
{
	t_vec		center;
	double		r;
	t_color		color;
	t_vec		nor_v;
	t_obj_type	parent_type;
	void		*parent;
}	t_disk;

typedef struct s_sphere
{
	t_vec	center;
	double	diameter;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_ms
{
	t_vec		center;
	t_mash_type	ms_type;
}	t_ms;

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
	t_disk	*bot;
	t_disk	*top;
}	t_cylinder;

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
	t_disk	*bot;
}	t_cone;

typedef struct s_light
{
	t_vec	center;
	double	ratio;
	t_color	color;
}	t_light;

/**
 * 	color -> ratio * color한 값
**/
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
#endif