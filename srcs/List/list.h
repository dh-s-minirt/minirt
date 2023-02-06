/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:48:59 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/01 16:54:04 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_light_list{
	int			size;
	const int	capacity = 100000;
	size_t		_node_type_size;
}	t_list;

#endif