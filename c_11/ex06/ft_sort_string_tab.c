/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 04:50:22 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 04:50:23 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (tab[0] == 0)
		return ;
	while (tab[i + 1] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (0 < ft_strcmp(tab[i], tab[j]))
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
int cmp_strcmp(char *s1, char *s2)
{
    return strcmp(s1, s2);
}

int main()
{
    char *test_strings[] = {
        /*"hello",
        "world",
        "apple",
        "orange",
        "banana",
        "kiwi",
        "grape",
        "mango",
        "pear",
        "cherry",
        "123",
        "456",
        "789",
        "OpenAI",
        "Language",
        "Model",
        "",
        "test",
        "example",
        NULL // Null-terminated array
    };

    int num_tests = 1;//sizeof(test_strings) 
    / sizeof(test_strings[0]) - 1; // Excluding NULL

    printf("Original Array:\n");
    for (int i = 0; i < num_tests; i++)
    {
        printf("%s\n", test_strings[i]);
    }

    ft_sort_string_tab(test_strings);

    printf("\nSorted Array:\n");
    for (int i = 0; i < num_tests; i++)
    {
        printf("%s\n", test_strings[i]);
    }

    return 0;
}
*/