/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:47:23 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 22:15:31 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

static void	_check_p3(FILE *fp)
{
	char	str[3];

	if (fscanf(fp, "%s", str) < 1)
		ft_exit("ppm : first_line should be P3");
	if (ft_strcmp("P3", str) != 0)
		ft_exit("ppm : first_line should be P3");
}

void	_get_ppm_info(t_ppm *ppm, FILE *fp)
{
	if (fscanf(fp, "%d %d %d", &ppm->width, &ppm->height, &ppm->max) < 2)
		ft_exit("ppm : info_line error.");
	if (ppm->width < 0 || ppm->width > MAX_PPM_SIZE || \
	ppm->height < 0 || ppm->width > MAX_PPM_SIZE || \
	ppm->max < 0 || ppm->max > 255)
		ft_exit("ppm : info_line error.");
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
		if (ppm->map[i].x > ppm->max || ppm->map[i].x < 0 \
		|| ppm->map[i].y > ppm->max || ppm->map[i].y < 0 \
		|| ppm->map[i].z > ppm->max || ppm->map[i].z < 0)
			ft_exit("ppm_parse error.");
		ppm->map[i] = vec_div(ppm->map[i], 255.999);
		i++;
	}
}

t_ppm	*parse_ppm(char *file)
{
	FILE		*fp;
	t_ppm		*ppm;

	fp = fopen(file, "r+");
	if (fp == NULL)
		ft_exit("ppm_parse error.");
	_check_p3(fp);
	ppm = ft_malloc(sizeof(t_ppm));
	_get_ppm_info(ppm, fp);
	_init_ppm_map(ppm);
	get_ppm_data(fp, ppm);
	fclose(fp);
	return (ppm);
}
