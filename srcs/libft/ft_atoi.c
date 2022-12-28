/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:32:48 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/07/07 15:47:19 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

static int	is_space(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == '\f' || ch == '\v'
		|| ch == '\r' || ch == ' ');
}

static int	make_return_value(unsigned long long result, int flag)
{
	if (result > LLONG_MAX && flag == 1)
		return (-1);
	else if (result -1 > LLONG_MAX && flag == -1)
		return (0);
	else
		return ((int) result * flag);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					flag;
	int					i;

	result = 0;
	i = 0;
	flag = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		flag = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != 0 && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (make_return_value(result, flag));
}
