/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:44:29 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/26 15:42:39 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_ppm.h"

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	argv_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

static int	is_space(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == '\f' || ch == '\v'
		|| ch == '\r' || ch == ' ');
}

int	atoi_err(char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (!is_space(str[i]) && str[i] != '\0')
		ft_exit("ppm : data error.");
	return (result * sign);
}

