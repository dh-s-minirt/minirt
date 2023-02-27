/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse_ppm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:29:20 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/27 16:27:13 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

void	print_ppm(t_ppm *ppm)
{
	printf("%d %d\n", ppm->width, ppm->height);
	for (int i = 0; i < ppm->height; i++){
		for (int j = 0; j < ppm->width; j++){
				t_color cur = ppm->map[i * ppm->width + j];
				printf("%lf %lf %lf ", cur.x, cur.y, cur.z);
		}
		printf("\n");
	}
}