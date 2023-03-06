/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:14 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/06 23:47:20 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

void	_init_ppm_map(t_ppm *ppm)
{
	t_color	*map;

	map = ft_malloc(sizeof(t_color) * ppm->height * ppm->width);
	ppm->map = map;
}

char	*str_ncpy(char *source, int n)
{
	char	*tmp;
	int		i;

	i = -1;
	if (ft_strlen(source) < (size_t)n)
		ft_exit("strncpy error\n");	
	tmp = ft_malloc(sizeof(char) * n + 1);
	while (++i < n)
		tmp[i] = source[i];
	tmp[i] = 0;
	return (tmp);
}

char	*get_norm_map_name(char *name)
{
	char	*tmp;
	char	*normal;

	tmp = str_ncpy(name, ft_strlen(name) - 4);
	normal = ft_strjoin(tmp, "_normal.ppm");
	printf("%s\n", normal);
	free(tmp);
	return 	(normal);
}

t_bool	has_normal(char *name)
{
	int 	fd;
	char	*normal;

	normal = get_norm_map_name(name);
	fd = open(normal, O_RDONLY);
	free(normal);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}