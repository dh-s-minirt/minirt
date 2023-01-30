/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:00:15 by daegulee          #+#    #+#             */
/*   Updated: 2023/01/30 20:22:19 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./matrix.h"
#include "../libft/libft.h"
#include <stdio.h>
void	print_mat(const t_mat4 a){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			printf("%lf ", a.m[i][j]);
		printf("\n");
	}
}