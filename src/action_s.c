/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:47 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 20:00:08 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void sb(t_stack *list)
{
	int tmp;
	int turn;

	tmp = list->top->data;
	turn = list->top->turn;
	list->top->data = list->top->next->data;
	list->top->turn = list->top->next->turn;
	list->top->next->data = tmp;
	list->top->next->turn = turn;
	printf("---------sb\n");
	display_list(list);
}

void sa(t_stack *list)
{
	int tmp;
	int turn;

	tmp = list->top->data;
	turn = list->top->turn;
	list->top->data = list->top->next->data;
	list->top->turn = list->top->next->turn;
	list->top->next->data = tmp;
	list->top->next->turn = turn;
	printf("--------sa\n");
	display_list(list);
}
void ss(t_stack *list_A, t_stack *list_B)
{
	sa(list_A);
	sb(list_B);
}