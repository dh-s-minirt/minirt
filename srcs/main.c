/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:45 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/01/02 10:38:51 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "./parsing/parsing.h"
#include "./color/color.h"
#include "./mlx_utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info_data	data;

	if (argc != 2)
		return (0);
	data.shape = NULL;
	data.canvas = canvas_new(CANVAS_WIDTH, CANVAS_HEIGHT);
	get_info_data(argv[1], &data);
	return (0);
}
