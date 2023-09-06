/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:37:37 by dscholz           #+#    #+#             */
/*   Updated: 2023/07/16 18:41:17 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	append_top_edge(int arr[4][4], char *vis_res);
void	append_bottom_edge(int arr[4][4], char *vis_res); 
void	append_left_edge(int arr[4][4], char *vis_res);
void	append_right_edge(int arr[4][4], char *vis_res);
void	set_null(char *vis_res, int size);
int		str_cmp(char *str1, char *str2);

int	is_visibility_valid(int arr[4][4], char *user_input)
{
	char	vis_res[31];

	set_null(vis_res, 31);
	append_top_edge(arr, vis_res);
	append_bottom_edge(arr, vis_res);
	append_left_edge(arr, vis_res);
	append_right_edge(arr, vis_res);
	if (str_cmp(vis_res, user_input) == 0)
		return (1);
	else
		return (0);
}
/*
int main(int argc, char *argv[]) {
    
    // Initialize array with some values
	int arr[4][4] = {
        {3, 2, 5, 1},
        {0, 4, 2, 7},
        {9, 8, 6, 1},
        {2, 4, 3, 0}};	

    // Print the array
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

	printf("(%d) result comparison", is_visibility_valid(arr, argv[1]));
	
	return 0;
}

*/
