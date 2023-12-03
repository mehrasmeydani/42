#include <stdio.h>
#include <bsd/string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

void	*ft_calloc(size_t nmemb, size_t size);
int 	ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
void	ft_strcat(char *dst, char *src);
char	*get_next_line(int fd);
char	*readfile(int fd, char *tmp, char *reeded);
char	*append(char *reeded, char *tmp);
char	*line(char *reeded);
char	*cut(char *reeded);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t			a;
	unsigned char	*p;

	a = 0;
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	p = (unsigned char *)ptr;
	while (a < (size * nmemb))
	{
		p[a] = '\0';
		a++;
	}
	return (ptr);
}

void	ft_strcat(char *dst, char *src)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(dst);
	b = 0;
	while (src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
}

int ft_strchr(char *s, char c)
{
	if (s == 0)
		return (0);
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(char *s)
{
	char	*d;
	size_t	a;

	if (!s)
		return (NULL);
	d = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (d == 0)
		return (NULL);
	a = 0;
	while (s[a] != '\0')
	{
		d[a] = s[a];
		a++;
	}
	d[a] = '\0';
	return (d);
}

char *get_next_line(int fd)
{
	static char	*reeded;
	char		*next_line;
	char		*tmp;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	reeded = readfile(fd, tmp, reeded);
	if (!reeded)
		return (NULL);
	next_line = line(reeded);
	if (!next_line)
		return (NULL);
	reeded = cut(reeded);
	return (next_line);
}

char	*readfile(int fd, char *tmp, char *reeded)
{
	int		charlen;

	charlen = 1;
	while (charlen > 0 && ft_strchr(reeded, '\n') == 0)
	{
		charlen = read(fd, tmp, BUFFER_SIZE);
		printf ("%d\n", charlen);
		if (charlen < 0)
		{
			if (reeded)
				free(reeded);
			if (tmp) 
				free(tmp);
			return (NULL);
		}
		if (charlen == 0)
			break ;
		tmp[charlen] = '\0';
		reeded = append(reeded, tmp);
		if (reeded == NULL)
			return (NULL);
	}
	free(tmp);
	return (reeded);
}

char	*append(char *reeded, char *tmp)
{
	char	*all;

	if (reeded == 0)
	{
		reeded = ft_strdup(tmp);
		return (reeded);
	}
	all = ft_calloc(ft_strlen(reeded) + BUFFER_SIZE + 1, 1);
	if (all == NULL)
	{
		free(reeded);
		free(tmp);
		return (NULL);
	}
	ft_strcat(all, reeded);
	ft_strcat(all, tmp);
	free(reeded);
	return (all);
}

char	*line(char *reeded)
{
	char	*next_line;
	int		a;

	a = 0;
	if (!reeded)
		return(NULL);
	while (reeded[a] != '\0' && reeded[a] != '\n')
		a++;
	if (reeded[a] == '\0')
	{
		next_line = ft_strdup(reeded);
		return (next_line);
	}
	next_line = ft_calloc(a + 2, 1);
	if (next_line == NULL)
		return (NULL);
	a = 0;
	while (reeded[a] != '\n')
	{
		next_line[a] = reeded[a];
		a++;
	}
	next_line[a] = '\n';
	next_line[a + 1] = '\0';
	return (next_line);
}

char	*cut(char *reeded)
{
	char	*tmp;
	int		a;

	a = 0;
	while (reeded[a] != '\0' && reeded[a] != '\n')
		a++;
	if (reeded[a] == '\0')
	{
		free(reeded);
		return (NULL);
	}
	a++;
	if (reeded[a] != '\0')
		tmp = ft_strdup(&reeded[a]);
	else
	{
		free(reeded);
		return (NULL);
	}
	free(reeded);
	return (tmp);
}

int main()
{
    int fd = open("file.txt", O_RDONLY, O_CREAT);
    
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
	printf("%d", read(3, 0, 1));


    return 0;
}
