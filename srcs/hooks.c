/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leehyunkyu <leehyunkyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:36:32 by leehyunkyu        #+#    #+#             */
/*   Updated: 2023/03/03 19:55:23 by leehyunkyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ESC 53
#define KET_EXIT 17
#include <stdlib.h>
#include <stdio.h>

int key_hook(int keycode, void *param)
{
    (void)param;
    
    if (keycode == ESC)
        exit(0);
    return (0);
}

int mouse_hook(void *param)
{
    (void)param;
    exit(0);
    return (0);
}
