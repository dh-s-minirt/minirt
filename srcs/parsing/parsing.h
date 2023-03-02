/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 03:55:22 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mini_rt.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../libft/libft.h"
# include "../color/color.h"
# include "../vector/vector.h"

# define SPHERE_SIZE 5
# define PLAIN_SIZE 5
# define CYLINDER_SIZE 7
# define CONE_SIZE 7
# define MS_SIZE 4

# define P_REFLECT "ref"
# define P_PHONG "pho"
# define P_FRESNEL "fre"
# define P_UV "uv"
# define P_SPECIAL "spe"

void	init_am_light(char **strs, t_info_data *data);
void	init_camera(char **strs, t_info_data *data);
void	init_light(char **strs, t_info_data *data);
void	init_sphere(char **strs, t_info_data *data);
void	init_plane(char **strs, t_info_data *data);
void	get_info_data(char *filename, t_info_data *data, int argc);
void	fill_camera_data(t_info_data *data);
void	init_cone(char **strs, t_info_data *data);
void	init_ms(char **strs, t_info_data *data);
int		get_shape_size(t_node *node);
int		get_valid_input_size(t_node *node, char **strs);
void	add_material_data(t_node *node, char **strs);
void	add_reflect(t_node *node);
void	add_phong(t_node *node, char **strs);
void	add_fresnel(t_node *node, char **strs);
void	add_uv(t_node *node);
void	add_special(t_node *node, char **strs);
char	*delete_last_newline(char *line);
t_bool	validation_color(t_color data);
t_disk	*_make_disk_cy(t_cylinder *cy, t_material mat, t_vec center, \
t_info_data *data);
#endif