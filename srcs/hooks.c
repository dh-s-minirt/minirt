/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:36:32 by leehyunkyu        #+#    #+#             */
/*   Updated: 2023/03/07 15:00:49 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define ESC 53
#define KET_EXIT 17

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	mouse_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
