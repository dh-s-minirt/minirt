/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:38:54 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/01/02 10:33:08 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_node	*node_new(void *data, t_data_type type)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(0);
	new->data = data;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	node_add_back(t_node **lst, t_node *new_node)
{
	t_node	*tmp;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

t_canvas	canvas_new(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}
