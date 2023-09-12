#include "libft.h"

static char	*alocate(size_t lens, size_t counte, size_t count)
{
	char	*out;

	if (counte && count)
		out = (char *)ft_calloc(lens - 1, sizeof(char));
	else if ((!counte && count) || (!count && counte))
		out = (char *)ft_calloc(lens, sizeof(char));
	else
		out = (char *)ft_calloc(lens + 1, sizeof(char));
	if (!out)
		return(out);
	return (out);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lens;
	size_t	i;
	size_t	count;
	size_t	counte;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	lens = ft_strlen(s1);
	while (i < ft_strlen(set))
	{
		if (s1[0] == set[i])
			count = 1;
		if (s1[lens - 1] == set[i])
			counte = 1;
		i++;
	}
}