
#include <stdio.h>
#include <stdlib.h>


typedef int t_bool;

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}

void	ft_exit(char *str)
{
	if (str == NULL)
	{
		printf("Error\n");
		perror("rt :");
	}
	else
		printf("Error\n rt: %s\n", str);
	exit(EXIT_FAILURE);
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

int main(void){
	printf("atoi_error : %d %d %d\n", atoi_err("s1"), atoi_err("-2147483648"),atoi_err("1"));
}