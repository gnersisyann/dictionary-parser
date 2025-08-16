#include "../include/ft_lib.h"
#define MAX_ENTRIES 41

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50

int	ft_isspace(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r'));
}

const char	*skip_spaces(const char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

const char	*line_mover(const char *line, const char *delimiter)
{
	line = delimiter + 1;
	line = skip_spaces(line);
	return (line);
}

const char	*delimiter_fixer(const char *line)
{
	const char	*delimiter;

	delimiter = ft_strchr(line, '\n');
	if (!delimiter)
		delimiter = line + ft_strlen(line);
	return (delimiter);
}

struct s_keyval	*parse_dictionary_keyval(const char *dictionary,
		struct s_keyval *dict)
{
	const char	*line;
	int			index;
	const char	*delimiter;

	line = dictionary;
	index = 0;
	while (*line && index < MAX_ENTRIES)
	{
		delimiter = ft_strchr(line, ':');
		if (delimiter)
		{
			ft_strncpy(dict[index].key, line, delimiter - line);
			dict[index].key[delimiter - line] = '\0';
			line = line_mover(line, delimiter);
			delimiter = delimiter_fixer(line);
			ft_strncpy(dict[index].value, line, delimiter - line);
			dict[index].value[delimiter - line] = '\0';
			index++;
			line = line_mover(line, delimiter);
		}
		else
			break ;
	}
	return (dict);
}
