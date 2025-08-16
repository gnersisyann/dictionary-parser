#include "../include/ft_lib.h"

int	length(int num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*res;
	int		i;

	if (num == 0)
		return ("0");
	len = length(num);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	i = len - 1;
	res[len] = '\0';
	while (num)
	{
		res[i] = num % 10 + 48;
		i--;
		num /= 10;
	}
	return (res);
}
