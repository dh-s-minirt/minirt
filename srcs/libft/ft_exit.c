/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:35:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/03/07 14:36:47 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_exit(char *str)
{
	if (str == NULL)
	{
		printf("Error\n");
		perror("rt :");
	}
	else
		printf("Error\nrt: %s\n", str);
	exit(EXIT_FAILURE);
}
