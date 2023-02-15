/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:33:32 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/02/16 04:47:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CHUNK 16

static void	_sub_(void *b, long long unit_a, size_t loop_dist)
{
	while (loop_dist)
	{
		((long long *) b)[0] = unit_a;
		((long long *) b)[1] = unit_a;
		((long long *) b)[2] = unit_a;
		((long long *) b)[3] = unit_a;
		((long long *) b)[4] = unit_a;
		((long long *) b)[5] = unit_a;
		((long long *) b)[6] = unit_a;
		((long long *) b)[7] = unit_a;
		((long long *) b)[8] = unit_a;
		((long long *) b)[9] = unit_a;
		((long long *) b)[10] = unit_a;
		((long long *) b)[11] = unit_a;
		((long long *) b)[12] = unit_a;
		((long long *) b)[13] = unit_a;
		((long long *) b)[14] = unit_a;
		((long long *) b)[15] = unit_a;
		b += CHUNK * 8;
		loop_dist -= 1;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			remain_dist;
	long long		unit_a;
	int				i;

	remain_dist = len % (CHUNK * 8);
	i = -1;
	unit_a = (unsigned char)c;
	while (++i < 7)
		unit_a |= (unit_a << 8);
	_sub_(b, unit_a, len / (CHUNK * 8));
	while (remain_dist)
	{
		((unsigned char *) b)[0] = (unsigned char)c;
		b++;
		remain_dist--;
	}
	return (b);
}
