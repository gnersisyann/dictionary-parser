#include "../include/ft_lib.h"

int	is_remainder(int number)
{
	if (number % 3 != 0)
		return ((number / 3) + 1);
	return (number / 3);
}

void	remainder_zero(struct s_keyval *dict, char *number, int length)
{
	char	*tmp;

	if (length < 3)
		return ;
	tmp = malloc(4);
	ft_strncpy(tmp, number, 3);
	print_three_digit(dict, tmp);
	number += 3;
	if (is_remainder(length) > 1 && ft_strcmp(tmp, "000"))
	{
		write(1, dict[27 + is_remainder(length)].value,
			ft_strlen(dict[27 + is_remainder(length)].value));
		write(1, " ", 1);
	}
	length -= 3;
	remainder_zero(dict, number, length);
}

void	remainder_two(struct s_keyval *dict, char *number, int length)
{
	char	*tmp;
	int		i;

	tmp = malloc(3);
	if (!number)
	{
		return ;
	}
	i = 0;
	while (i < 2)
	{
		tmp[i] = number[i];
		i++;
	}
	tmp[3] = '\0';
	print_two_digit(dict, tmp);
	number += 2;
	if (is_remainder(length) > 1)
	{
		write(1, dict[27 + is_remainder(length)].value,
			ft_strlen(dict[27 + is_remainder(length)].value));
		write(1, " ", 1);
	}
	length -= 2;
	remainder_zero(dict, number, length);
}

void	remainder_one(struct s_keyval *dict, char *number, int length)
{
	char	tmp;

	if (!number)
	{
		return ;
	}
	tmp = number[0];
	print_one_digit(dict, tmp);
	number += 1;
	if (is_remainder(length) > 1)
	{
		write(1, dict[27 + is_remainder(length)].value,
			ft_strlen(dict[27 + is_remainder(length)].value));
		write(1, " ", 1);
	}
	length--;
	remainder_zero(dict, number, length);
}

void	working(struct s_keyval *dict, char *number)
{
	int	length;

	length = ft_strlen(number);
	if (length % 3 == 0)
		remainder_zero(dict, number, length);
	else if (length % 3 == 1)
		remainder_one(dict, number, length);
	else
		remainder_two(dict, number, length);
}
