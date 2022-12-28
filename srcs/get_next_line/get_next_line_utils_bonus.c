/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:20 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/27 13:18:59 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

void	ft_strlcpy1(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
}

void	ft_cat_str(char *result, char *buffer, size_t size)
{
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (result[len] != 0)
		len++;
	while (len < size)
	{
		result[len] = buffer[idx];
		len++;
		idx++;
	}
	result[len] = 0;
}

void	ft_substr1(char *s, unsigned int start, size_t len, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len)
	{
		if (i < len)
			s[i] = s[start];
		else
			s[i] = 0;
		start++;
		i++;
	}
}

char	*fill_str(t_file *file_node, char *str)
{
	char	*result;
	int		s_len;

	if (str == 0)
	{
		result = malloc (sizeof(char) * (file_node->size + 1));
		ft_strlcpy1(result, file_node->buffer, file_node->size + 1);
		return (result);
	}
	s_len = 0;
	while (str[s_len] != 0)
		s_len++;
	result = malloc (sizeof(char) * (file_node->size + s_len + 1));
	ft_strlcpy1(result, str, s_len + 1);
	free(str);
	ft_cat_str(result, file_node->buffer, s_len + file_node->size);
	return (result);
}

t_file	*ft_lstnew1(int fd)
{
	t_file	*node;

	node = malloc (sizeof(t_file));
	node->fd = fd;
	node->next = 0;
	node->size = 0;
	node->cnt_newline = 0;
	return (node);
}
