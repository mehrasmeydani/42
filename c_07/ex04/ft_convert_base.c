/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:12:37 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/20 17:12:47 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int *check);
void	ft_putnbr_base(int nbr, char *base, char *dest);
int		base_check(char *base, int *len);

int	check(char *base_from)
{
	int	i;

	if (!base_check(base_from, &i))
		return (0);
	i = 0;
	while (*base_from)
	{
		i++;
		base_from++;
	}
	return (i);
}

char	*len(char *str, char *base, int *sign, int *len)
{
	int	i;
	int	j;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = *sign * -1;
		str++;
	}
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (str[i] == base [j])
				*len = *len + 1;
		}
		if (*len - 1 != i)
			return (str);
	}
	return (str);
}

int	to_deci(char *str, char *base, int len_base, int *len)
{
	int	res;
	int	i;
	int	j;
	int	power;

	res = 0;
	power = 1;
	i = (*len >= 0) * *len + (*len < 0) * -(*len);
	while (--i >= 0)
	{
		j = -1;
		while (base[++j])
		{
			if (str[i] == base [j])
			{
				if (*len > 0)
					res = res + (j * power);
				if (*len < 0)
					res = res - (j * power);
				power *= len_base;
			}
		}
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		base_len;
	int		res_deci;
	int		res_deci2;
	int		res_len;

	base_len = 0;
	res_len = 0;
	res_deci = ft_atoi_base(nbr, base_from, &res_deci2);
	if (check(base_from) < 2 || check(base_to) < 2)
		return (NULL);
	res_deci2 = res_deci;
	base_len = check(base_to);
	while (res_deci2 != 0 && ++res_len)
		res_deci2 /= base_len;
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (0);
	}
	res[0] = '\0';
	ft_putnbr_base(res_deci, base_to, res);
	return (res);
}
/*
#include <stdio.h>

int main() {
    char* result;
    char* input[] = {
        // Valid Inputs
        "1010", "01", "0123456789",       
        //1 Binary to Decimal
        "FF", "0123456789ABCDEF", "01",  
        //2 Hexadecimal to Binary
        "321", "01234567", "0123456789",  
        //3 Decimal to Octal
        "101010", "01", "0123456789ABCDEF",  
        //4 Binary to Hexadecimal
        "1A4", "0123456789ABCDEF", "01234567",  
        //5 Hexadecimal to Octal
        "1001", "0123456789", "01",  
        //6 Decimal to Binary
        "321", "0123456789", "0123456789ABCDEF",  
        //7 Decimal to Hexadecimal
        "A7", "0123456789ABCDEF", "0123456789",  
        //8 Hexadecimal to Decimal
        "77", "01234567", "0123456789ABCDEF",  
        //9 Octal to Hexadecimal
        "15", "0123456789ABCDEF", "01234567",  
        //10 Decimal to Octal

        // Invalid Inputs
        "1010", "01+", "0123456789",      
        //11 Invalid Base (contains '+')
        "FF", "\tABC", "01",             
        //12 Invalid Base (contains non-printable characters)
        "1A4", "0123456789", "",         
        //13 Invalid Base (empty base_to)
        "1101", "01", "012+3456789",     
        //14 Invalid Base (contains '+')
        "1101", "01", "",                
        //15 Invalid Base (empty base_to)
        "1010", "01", "01234567",        
        //16 Invalid Input (base_from too small for binary)
        "12345", "0123456789", "01",     
        //17 Invalid Input (base_from too large for binary)
        "1010", "01234567", "01",        
        //18 Invalid Input (base_from too large for binary)
        "FF", "01", "0123456789ABCDEF",  
        //19 Invalid Input (base_from too small for hexadecimal)
        "ABC123", "0123456789ABCDEF", "01234567",  
        //20 Invalid Input (base_from too large for hexadecimal)
        "1A4", "0123456789", "01",      
        //21 Invalid Input (base_from too large for octal)
        "12", "01", "0123456789ABCDEF",  
        //22 Invalid Input (base_to too small for binary)
        "1010", "01", "0123456789ABCDEF", 
        //23 Invalid Input (base_to too small for hexadecimal)
        "15", "0123456789", "01"        
        //24 Invalid Input (base_to too small for octal)
    };

    int num_tests = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < num_tests; i += 3) {
        result = ft_convert_base(input[i], input[i + 1], input[i + 2]);
        if (result != NULL) {
  	printf("Test%d:Passed-Input:(%s)Base From:(%s)Base To:(%s)Result:(%s)\n",
                   (i / 3) + 1, input[i], input[i + 1], input[i + 2], result);
            free(result);
        } else {
            printf("Test%d:Failed-Input:(%s)Base From:(%s)Base To:(%s)\n",
                   (i / 3) + 1, input[i], input[i + 1], input[i + 2]);
        }
    }

    return 0;
}*/
