/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:14 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/27 00:44:35 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

void	_init_ppm_map(t_ppm *ppm)
{
	t_color	*map;
	int		i;

	i = 0;
	map = ft_malloc(sizeof(t_color) * ppm->height * ppm->width);
	ppm->map = map;
}
