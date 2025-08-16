#include "../include/ft_lib.h"

size_t	count_file_bytes(const char *file_path)
{
	int				file;
	size_t			byte_count;
	char			buffer[1];

	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		return (-1);
	}
	byte_count = 0;
	while (read(file, buffer, 1) > 0)
		byte_count++;
	if (read(file, buffer, 1) == -1)
	{
		close(file);
		return (-1);
	}
	close(file);
	return (byte_count);
}

unsigned char	*read_and_fill(const char *file_path,
		unsigned char *symbols, size_t byte_count)
{
	int		read_count;
	int		file;

	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		return (NULL);
	}
	read_count = read(file, symbols, byte_count);
	if (read_count == -1)
	{
		free(symbols);
		close(file);
		return (NULL);
	}
	close(file);
	symbols[byte_count] = '\0';
	return (symbols);
}

char	*parse_dictionary(const char *file_path)
{
	unsigned char	*symbols;
	size_t			byte_count;

	byte_count = count_file_bytes(file_path);
	symbols = malloc(byte_count + 1);
	symbols = read_and_fill(file_path, symbols, byte_count);
	if (!symbols)
	{
		return (NULL);
	}
	return ((char *)symbols);
}
