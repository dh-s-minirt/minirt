/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:20:28 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 16:37:50 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_PPM_H
# define PARSING_PPM_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mini_rt.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../libft/libft.h"
# include "../color/color.h"
# include "../vector/vector.h"
# include "../Matrix/matrix.h"

# define MAX_PPM_SIZE 2400

# define R 0
# define G 1
# define B 2

typedef struct s_ppm
{
	t_color	**map;
	int		width;
	int		height;
	int		max;
}	t_ppm;

int		argv_len(char **argv);
void	argv_free(char **argv);
void	_get_ppm_h_w(char *str, t_ppm *ppm);
void	_get_ppm_max_color(char *str, t_ppm *ppm);
void	_get_ppm_data(int fd, t_ppm *ppm);
void	_get_ppm_info(int fd, t_ppm *ppm);
int		atoi_err(char *str);
t_ppm	*parse_ppm(char *file);
void	print_ppm(t_ppm *ppm);

#endif