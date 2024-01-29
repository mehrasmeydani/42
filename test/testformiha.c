#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}


int main(int argc, char **argv)
{
	int i;
	char *str;

	i = 1;
	while (i < argc)
	{
		str = ft_itoa(ft_atoi(argv[i]));
		if (ft_strcmp(argv[i], str))
			printf("%d", 0);
		else
			printf("%d", 1);
		free (str);
		i++;
	}
	return (0);
}