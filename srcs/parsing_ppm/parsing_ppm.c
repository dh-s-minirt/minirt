/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:14 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 14:53:46 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

typedef struct s_ppm
{
	t_color	**map;
	int		width;
	int		height;
	int		max;
}	t_ppm;

static void	_check_p3(int fd)
{
	const char	*str = get_next_line(fd);

	if (str == NULL || ft_strcmp("P3\n", str) != 0)
	{
		free(str);
		ft_exit("ppm : first_line should be P3");
	}
	else
		free(str);
}

static void	_get_ppm_h_w(char *str, t_ppm *ppm)
{
	char	**argv;

	argv = ft_split(str, ' ');
	if (argv == NULL || argv_len(argv) != 2)
		ft_exit("ppm : info_line error.");
	ppm->width = ft_atoi(argv[0]);
	ppm->height = ft_atoi(argv[1]);
	if (ppm->width < 0 || ppm->width > MAX_PPM_SIZE \
	|| ppm->height < 0 || ppm->height > MAX_PPM_SIZE)
		ft_exit("ppm : info_line error.");
	argv_free(argv);
}

static void	_get_ppm_info(int fd, t_ppm *ppm)
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
				
			info_cnt--;
			
		}
		free(str);		
	}
}

void	parse_ppm(char *file)
{
	const int	fd = open(file, O_RDONLY);
	t_ppm		*ppm;

	if (fd < 0)
		ft_exit(NULL);
	_check_p3(fd);
	ppm = ft_malloc(sizeof(t_ppm));
	_get_ppm_info(fd, ppm);
}