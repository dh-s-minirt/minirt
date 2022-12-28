/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:32:48 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 20:10:01 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == '\f' || ch == '\v'
		|| ch == '\r' || ch == ' ');
}

static double	make_return_value(int i, const char *str, \
			double result, int flag)
{
	int	tmp;

	while (str[i] != 0 && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	tmp = 1;
	while (str[i] != 0 && '0' <= str[i] && str[i] <= '9')
	{
		result += (str[i] - '0') / (double)(tmp * 10);
		tmp *= 10;
		i++;
	}
	return (result * (double) flag);
}

double	ft_atof(const char *str)
{
	double	result;
	int		flag;
	int		i;

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
	return (make_return_value(i, str, result, flag));
}
