/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leehyunkyu <leehyunkyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:36:32 by leehyunkyu        #+#    #+#             */
/*   Updated: 2023/03/03 19:52:56 by leehyunkyu       ###   ########.fr       */
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

int mouse_hook(int button, int x, int y, void *param)
{
    (void)param;
    (void)button;
    (void)x;
    (void)y;
    exit(0);
    return (0);
}
