/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/28 11:28:46 by hyunkyle         ###   ########.fr       */
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

void	init_am_light(char **strs, t_info_data *data);
void	init_camera(char **strs, t_info_data *data);
void	init_light(char **strs, t_info_data *data);
void	init_sphere(char **strs, t_info_data *data);
void	init_plane(char **strs, t_info_data *data);
void	get_info_data(char *filename, t_info_data *data);
void	fill_camera_data(t_info_data *data);
void	init_cone(char **strs, t_info_data *data);

#endif