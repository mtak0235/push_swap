/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:30:07 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 19:47:35 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_pivot_turn(t_stack *list, int size)
{
	list->pivot_small = 1 + size / 3;
	list->pivot_big = 1 + list->pivot_small + size / 3;
}

void compare_list_arr_fill_turn(int *arr, t_stack *list, int size)
{
	t_node *node;
	int i;

	node = list->top;
	while (1)
	{
		i = 0;
		while(i < size)
		{
			if (node->data == arr[i])
				node->turn = i + 1;
			i++;
		}
		node = node->next;
		if (node == list->top)
			break ;
	}	
}

int *put_data_arr(int *arr, t_stack *list, int size)
{
	t_node *node;
	int i;

	node = list->top;
	if (!(arr = malloc(sizeof(int) * size)))
		return (0);
	arr[0] = node->data;
	node = node->next;
	i = 1;
	while (node != list->top)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	return (arr);
}

void quick_sort(int *arr, int start, int end)
{
	int piv;
	int i;
	int j;
	int tmp;

	if (start >= end)
		return ;
	piv = start;
	i = piv + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[piv])
			i++;
		while (j > start && arr[j] >= arr[piv])
			j--;
		if (i > j)
		{
			tmp = arr[j];
			arr[j] = arr[piv];
			arr[piv] = tmp;
		}
		else
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void	find_pivot(t_stack *list, int size)
{
	int *arr;
	
	arr = put_data_arr(arr, list, size);
	quick_sort(arr, 0, size - 1);
	compare_list_arr_fill_turn(arr, list, size);
	(size <= 3) ? 0 : align_pivot_turn(list, size);
	free(arr);
}