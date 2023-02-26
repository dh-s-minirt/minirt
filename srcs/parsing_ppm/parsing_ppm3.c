/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:18:27 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 16:47:23 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

static int	_color_change(int color)
{
	if (color == B)
		return (R);
	else
		return (color + 1);
}

void	_get_one_row(char **argv, t_ppm *ppm, int row)
{
	int			i;
	int			val;
	int			color_val;
	t_arr_vec3	color;
	int			ppm_col;

	color_val = R;
	ppm_col = 0;
	i = -1;
	while (++i < ppm->width * 3)
	{
		val = atoi_err(argv[i]);
		if (val < 0 && val > ppm->max)
			ft_exit("ppm : data_error.");
		color.v[color_val] = (double)val / 255.999;
		if (color_val == R)
			ppm->map[row][ppm_col++] = arr_vec3_2_vec(color);
		_color_change(color_val);
	}
}

void	_get_ppm_data(int fd, t_ppm *ppm)
{
	char	*str;
	char	**argv;
	int		ppm_row;

	ppm_row = -1;
	while (++ppm_row != ppm->height)
	{
		str = get_next_line(fd);
		if (str == NULL)
			ft_exit("ppm : data_error.");
		argv = ft_split(str, ' ');
		if (argv == NULL || argv_len(argv) != ppm->width * 3)
			ft_exit("ppm : data_error.");
		_get_one_row(argv, ppm, ppm_row);
		free(str);
		argv_free(argv);
	}
}
