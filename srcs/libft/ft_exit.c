/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:35:51 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 16:17:20 by daegulee         ###   ########.fr       */
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