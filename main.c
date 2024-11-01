/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:44:59 by ganersis          #+#    #+#             */
/*   Updated: 2024/09/26 17:03:06 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./headers/ft_lib.h"

int	two_arguments(struct s_keyval *values, const char *data, char *argv)
{
	if (ft_strlen(argv) > 39)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	data = (parse_dictionary("./dictionaries/numbers.dict"));
	if (!data)
		return (0);
	parse_dictionary_keyval(data, values);
	if (argv[0] == '0')
	{
		write(1, values[0].value, ft_strlen(values[0].value));
		write(1, "\n", 1);
		return (1);
	}
	working(values, argv);
	return (1);
}

int	three_arguments(struct s_keyval *values,
		const char *data, char *dict, char *argv)
{
	if (ft_strlen(argv) > 39)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	data = parse_dictionary(dict);
	if (!data)
		return (0);
	parse_dictionary_keyval(data, values);
	if (argv[0] == '0')
	{
		write(1, values[0].value, ft_strlen(values[0].value));
		write(1, "\n", 1);
		return (1);
	}
	working(values, argv);
	return (1);
}

int	main(int argc, char **argv)
{
	const char		*data = {};
	struct s_keyval	values[MAX_ENTRIES];

	if (argc == 2)
	{
		if (!(two_arguments(values, data, argv[1])))
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		write(1,"\n",1);
	}
	else if (argc == 3)
	{
		if (!(three_arguments(values, data, argv[1], argv[2])))
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
		write(1,"\n",1);
	}
}
