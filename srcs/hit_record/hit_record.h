/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:49:23 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 09:11:24 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include <math.h>
# include "../vector/vector.h"
# include "../settings/setting.h"
# include "../Matrix/matrix.h"
# include "../mini_rt.h"

typedef struct s_hit_rec
{
	double	t_near;
	t_vec	hit_normal;
	t_vec	contact_point;
	t_bool	is_hit;
}	t_hit_rec;

#endif