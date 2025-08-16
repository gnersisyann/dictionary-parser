#include "../include/ft_lib.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char	*ptr;
	char	*tmp;

	tmp = (char *)src;
	ptr = dest;
	while (n && *tmp)
	{
		*dest++ = *tmp++;
		n--;
	}
	while (n)
	{
		*dest++ = '\0';
		--n;
	}
	return (ptr);
}
