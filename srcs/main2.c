/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:33:59 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/27 00:06:20 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "./parsing/parsing.h"
#include "./color/color.h"
#include "./mlx/mlx.h"
// #include "./mlx_utils.h"
#include <stdio.h>
#include "./settings/setting.h"
#include "./hit_record/hit_record.h"
#include "./render/render.h"
#include "./parsing_ppm/parsing_ppm.h"

int main(int argc, char **argv)
{
	argc =0;
	char *str = argv[1];
	t_ppm *ppm = parse_ppm(str);
	printf("\n\n");
	print_ppm(ppm);
}