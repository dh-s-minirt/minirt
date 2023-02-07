/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:38:54 by hyunkyu           #+#    #+#             */
/*   Updated: 2023/02/07 09:45:10 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_node	*node_new(void *data, t_obj_type type)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(EXIT_FAILURE);
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

void	light_node_add_back(t_light_node **head, t_light_node *new_node)
{
	t_light_node	*tmp;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

t_light_node	*new_light_node(void *data, t_light_type type)
{
	t_light_node	*node;

	node = malloc(sizeof(t_light_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->data = data;
	node->type = type;
	node->next = NULL;
	return (node);
}

t_canvas	canvas_new(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}
