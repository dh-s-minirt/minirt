/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:47:23 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/27 23:25:57 by daegulee         ###   ########.fr       */
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

void	_get_ppm_info(int fd, t_ppm *ppm, FILE *fp)
{
	char	*str;
	int		info_cnt;
	char	buffer[50];
	int		i;

	i = -1;
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
	while (++i < 4)
		fscanf(fp, "%s", buffer);
}

void	get_ppm_data(FILE *fp, t_ppm *ppm)
{
	int	i;

	i = 0;
	while (i < ppm->height * ppm->width)
	{
		if (fscanf(fp, "%lf %lf %lf", \
		&((ppm->map[i]).x), &((ppm->map[i]).y), &((ppm->map[i]).z)) < 3)
			ft_exit("ppm_parse error.");
		ppm->map[i] = vec_div(ppm->map[i], 255.999);
		i++;
	}
}

static void	_clear_gnl(int fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
	}
	close(fd);
}

t_ppm	*parse_ppm(char *file)
{
	FILE		*fp;
	int			fd;
	t_ppm		*ppm;

    fp = fopen(file, "r+");
	fd = open(file, O_RDONLY);
	if (fp == NULL && fd < 0)
		ft_exit("ppm_parse error.");
	_check_p3(fd);
	ppm = ft_malloc(sizeof(t_ppm));
	_get_ppm_info(fd, ppm, fp);
	_clear_gnl(fd);
	_init_ppm_map(ppm);
	get_ppm_data(fp, ppm);
	fclose(fp);
	return (ppm);
}
