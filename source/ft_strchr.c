#include "../headers/ft_lib.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
		{
			return (NULL);
		}
	}
	return ((char *)s);
}
