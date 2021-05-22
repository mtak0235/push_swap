/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:20:04 by mtak              #+#    #+#             */
/*   Updated: 2021/05/22 22:35:13 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void sort(t_box *box)
{

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
	/* 정렬을 한 다음에 "turn"변수에 1등부터 꼴등까지 붙이고,  3을 나눠서 임시피 2개 정한다.
	즉 2임시피봇의 "turn"을   pivot_small, pivot_big 에 저장한다.
	*/
	t_node *node;
	int *arr;
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
	quick_sort(arr, 0, size - 1);
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
		if (node != list->top)
			break ;
	}
}
void	push_swap(t_box *box)
{
	find_pivot(box->A, box->A->cnt_idx);
	sort(box);
	//display_list(box->B);
}

int main(int ag, char **av)
{
	t_box *box;

	if (ag < 2)
		return (1);
	if (!(box = init_box(box, (char **)av, ag - 1)))
		return (EXIT_FAILED);
	push_swap(box);
	//free_machine(&box);
	return (EXIT_SUCCESSED);
}