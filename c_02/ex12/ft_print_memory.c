/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:12:47 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/12 13:12:49 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printhex(unsigned char dec)
{
	int	first;
	int	last;

	first = 0;
	last = 0;
	first = dec / 16;
	last = dec % 16;
	if (first < 10)
		first += '0';
	else
		first += 'a' - 10;
	write(1, &first, 1);
	if (last < 10)
		last += '0';
	else
		last += 'a' - 10;
	write(1, &last, 1);
}

void	print_memoryaddress(long addr)
{
	unsigned char	hex[8];
	int				i;

	i = 0;
	while (i < 8)
	{
		hex[i] = addr % 256;
		addr /= 256;
		i++;
	}
	while (i != 0)
	{
		printhex(hex[i]);
		i--;
	}
}

void	addspaces(int size)
{
	int	spaces;

	spaces = 16 - (size % 16) - 1;
	while (spaces-- != 0)
	{
		write(1, "  ", 2);
		if (spaces % 2 == 0)
			write(1, " ", 1);
	}
}

void	printcontents(int *i, unsigned int *j,
	void *addr, unsigned int size)
{
	while (++*i < 16 && *j <= size)
	{
		printhex(*(int *)(addr + *j));
		if (*i % 2 == 1)
			write(1, " ", 1);
		(*j)++;
	}
	if (*j > size)
		addspaces(size);
	*j -= *i;
	*i = -1;
	while (++*i < 16 && *j <= size)
	{
		if (*(char *)(addr + *j) < 32 || *(char *)(addr + *j) > 126)
			write(1, ".", 1);
		else
			write(1, addr + *j, 1);
		(*j)++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int				i;
	unsigned int	j;

	j = 0;
	while (j < size)
	{
		i = -1;
		print_memoryaddress((long) addr + j * 256);
		write(1, ": ", 2);
		printcontents(&i, &j, addr, size);
		write(1, "\n", 1);
	}
}
/*

int main()
{
unsigned char a[] = {158, 1,2,3,4,5,6,7,8,9,10
,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26
,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51
,52,53,54,55,56,57,58,59,60,61,62,63,64,65
,66,67,68,69,70,71,72,73,74,75,76,77,78,79
,80,81,82,83,84,85,86,87,88,89,90,91,92,93
,94,95,96,97,98,99,100,101,102,103,104,105,106,
107,108,109,110,111,112,113,114,115,116,117
,118,119,120,121,122,123,124,125,126,127,128,129,130};
void *c = a;

ft_print_memory(c, 250);
}*/
