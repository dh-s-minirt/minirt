/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:46:18 by daegulee          #+#    #+#             */
/*   Updated: 2022/12/28 16:53:03 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <math.h>
# define PI 3.1415926535897932385

//math_util.c
double	clamp(double x, double min, double max);
double	degrees_to_radians(double degrees);
//

#endif