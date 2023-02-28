/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ppm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaegyu <idaegyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:14 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/28 19:48:32 by idaegyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

void	_init_ppm_map(t_ppm *ppm)
{
	t_color	*map;

	map = ft_malloc(sizeof(t_color) * ppm->height * ppm->width);
	ppm->map = map;
}
