/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:02:02 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/09 19:05:28 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size_of)
{
	void	*p;

	p = malloc(size_of);
	if (p == NULL)
	{
		perror("rt : ");
		exit(EXIT_FAILURE);
	}
	ft_memset(p, 0, size_of);
	return (p);
}
