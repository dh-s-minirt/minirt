/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:20:28 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 14:52:18 by daegulee         ###   ########.fr       */
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

# define MAX_PPM_SIZE 2400

int		argv_len(char **argv);
void	argv_free(char **argv);

#endif