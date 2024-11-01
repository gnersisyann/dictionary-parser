#include "../headers/ft_lib.h"

void	print_one_digit(struct s_keyval *dict, char digit)
{
	int	number;

	if (digit - '0' != 0)
	{
		number = ft_atoi(&digit);
		write(1, dict[number].value, ft_strlen(dict[number].value));
		write(1, " ", 1);
	}
}

void	print_two_digit_helper(struct s_keyval *dict, int number)
{
	write(1, dict[number].value, ft_strlen(dict[number].value));
	write(1, " ", 1);
}

void	print_two_digit_helperr(struct s_keyval *dict, int number)
{
	if (number > 10 && number < 20)
		print_two_digit_helper(dict, number);
	else
	{
		print_two_digit(dict, ft_itoa((number / 10) * 10));
		print_one_digit(dict, (number % 10) + '0');
	}
}

void	print_two_digit(struct s_keyval *dict, char *digits)
{
	int		number;

	if (digits[0] == '0')
	{
		print_one_digit(dict, digits[1]);
		return ;
	}
	number = ft_atoi(digits);
	if (number % 10 == 0)
	{
		if (number > 20)
			write(1, dict[20 + ((number - 20) / 10)].value,
				ft_strlen(dict[20 + ((number - 20) / 10)].value));
		else
			write(1, dict[number].value, ft_strlen(dict[number].value));
		write(1, " ", 1);
	}
	else
	{
		if (number > 10 && number < 20)
			print_two_digit_helper(dict, number);
		else
			print_two_digit_helperr(dict, number);
	}
}

void	print_three_digit(struct s_keyval *dict, char *digits)
{
	int		number;

	if (digits[0] == '0')
		print_two_digit(dict, digits + 1);
	else
	{
		number = ft_atoi(digits);
		write(1, dict[number / 100].value, ft_strlen(dict[number / 100].value));
		write(1, " hundred ", 9);
		if ((number % 100) >= 0 && (number % 100) <= 9)
			print_one_digit(dict, (number % 100) + '0');
		else
			print_two_digit(dict, ft_itoa(number % 100));
	}
}
