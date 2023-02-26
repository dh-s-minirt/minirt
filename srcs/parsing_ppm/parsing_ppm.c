/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:14 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 16:44:52 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

static void	_check_p3(int fd)
{
	char	*str; 
	
	str = get_next_line(fd);
	if (str == NULL || ft_strcmp("P3\n", str) != 0)
	{
		free(str);
		ft_exit("ppm : first_line should be P3");
	}
	else
		free(str);
}

void	_init_ppm_map(t_ppm *ppm)
{
	t_color	**map;
	int		i;

	i = 0;
	map = ft_malloc(sizeof(t_color *) * ppm->height);
	while (i < ppm->height)
		map[i++] = ft_malloc(sizeof(t_color) * ppm->width);
	ppm->map = map;
}

t_ppm	*parse_ppm(char *file)
{
	const int	fd = open(file, O_RDONLY);
	t_ppm		*ppm;

	if (fd < 0)
		ft_exit(NULL);
	_check_p3(fd);
	ppm = ft_malloc(sizeof(t_ppm));
	_get_ppm_info(fd, ppm);
	_init_ppm_map(ppm);
	_get_ppm_data(fd, ppm);
	close(fd);
	return (ppm);
}
