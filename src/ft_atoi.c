#include "../include/ft_lib.h"

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	res;
	int	negative;

	negative = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[j] == '0' && ft_strlen(str) != 1)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}
