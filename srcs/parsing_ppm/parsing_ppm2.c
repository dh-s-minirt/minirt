/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:14:45 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 16:48:37 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

void	_get_ppm_h_w(char *str, t_ppm *ppm)
{
	char	**argv;

	argv = ft_split(str, ' ');
	if (argv == NULL || argv_len(argv) != 2)
		ft_exit("ppm : info_line error.");
	ppm->width = atoi_err(argv[0]);
	ppm->height = atoi_err(argv[1]);
	if (ppm->width < 0 || ppm->width > MAX_PPM_SIZE \
	|| ppm->height < 0 || ppm->height > MAX_PPM_SIZE)
		ft_exit("ppm : info_line error.");
	argv_free(argv);
}

void	_get_ppm_max_color(char *str, t_ppm *ppm)
{
	const int	val = atoi_err(str);

	if (val < 0 || val > 255)
		ft_exit("ppm : info_line error.");
	ppm->max = val;
}

void	_get_ppm_info(int fd, t_ppm *ppm)
{
	char	*str;
	int		info_cnt;

	info_cnt = 2;
	while (info_cnt)
	{
		str = get_next_line(fd);
		if (str == NULL)
			ft_exit("ppm : info_line error.");
		if (str[0] != '#')
		{
			if (info_cnt == 2)
				_get_ppm_h_w(str, ppm);
			else
				_get_ppm_max_color(str, ppm);
			info_cnt--;
		}
		free(str);
	}
}
