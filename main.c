#include "./include/ft_lib.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	process_number(struct s_keyval *values, const char *dict_path, char *number)
{
	const char	*data;

	data = parse_dictionary(dict_path);
	if (!data)
		return (0);
	parse_dictionary_keyval(data, values);
	if (number[0] == '0' && ft_strlen(number) == 1)
	{
		write(1, values[0].value, ft_strlen(values[0].value));
		write(1, "\n", 1);
		return (1);
	}
	working(values, number);
	write(1, "\n", 1);
	return (1);
}

int	validate_and_process(char *dict_path, char *number)
{
	struct s_keyval	values[MAX_ENTRIES];

	if (!is_valid_number(number))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_strlen(number) > 39)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!process_number(values, dict_path, number))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (!validate_and_process("./dictionaries/numbers.dict", argv[1]));
	}
	else if (argc == 3)
	{
		return (!validate_and_process(argv[1], argv[2]));
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
