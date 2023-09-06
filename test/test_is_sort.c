/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgardesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:34:48 by mgardesh          #+#    #+#             */
/*   Updated: 2023/07/27 01:34:50 by mgardesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int compare_integers(int a, int b)
{
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

void test_ft_is_sort(int test_num, int *arr, int length)
{
    int result = ft_is_sort(arr, length, compare_integers);
    if (result == 1)
        printf("Test %d: The array is sorted.\n", test_num);
    else
        printf("Test %d: The array is not sorted.\n", test_num);
}

int main()
{
    int test1_arr[] = {1, 3, 5, 7, 9};
    int test2_arr[] = {9, 7, 5, 3, 1};
    int test3_arr[] = {1, 2, 3, 4, 5};
    int test4_arr[] = {5, 4, 3, 2, 1};
    int test5_arr[] = {3, 5, 1, 7, 9};
    int test6_arr[] = {9, 1, 7, 5, 3};
    int test7_arr[] = {1, 1, 1, 1, 1};
    int test8_arr[] = {2, 2, 2, 2, 2};
    int test9_arr[] = {5};
    int test10_arr[] = {5, 5};

    int length = sizeof(test1_arr) / sizeof(test1_arr[0]);

    test_ft_is_sort(1, test1_arr, length);
    test_ft_is_sort(2, test2_arr, length);
    test_ft_is_sort(3, test3_arr, length);
    test_ft_is_sort(4, test4_arr, length);
    test_ft_is_sort(5, test5_arr, length);
    test_ft_is_sort(6, test6_arr, length);
    test_ft_is_sort(7, test7_arr, length);
    test_ft_is_sort(8, test8_arr, length);
    test_ft_is_sort(9, test9_arr, 1);
    test_ft_is_sort(10, test10_arr, 2);

    return 0;
}
