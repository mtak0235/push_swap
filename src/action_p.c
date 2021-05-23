/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:34:16 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 20:03:33 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void pa(t_stack *list_B, t_stack *list_A)
{
	t_node *tmp;

	tmp = list_B->top;
	list_B->top->prev = list_B->bottom;
	list_B->bottom->next = list_B->top->next;
	list_B->top = tmp->next;

	list_A->top->prev = tmp;
	list_A->bottom->next = tmp;
	tmp->prev = list_A->bottom;
	tmp->next = list_A->top;
	list_A->top = tmp;
	printf("------pa\n");
	display_list(list_A);
	printf("=======list B\n");
	display_list(list_B);
}

void pb(t_stack *list_A, t_stack *list_B)
{
	t_node *tmp;

	tmp = list_A->top;
	list_A->top->prev = list_A->bottom;
	list_A->bottom->next = list_A->top->next;
	list_A->top = tmp->next;

	if (!list_B->cnt_idx)
	{
		list_B->cnt_idx = 1;
		list_B->top = tmp;
		list_B->bottom = tmp;
	}

	list_B->top->prev = tmp;
	list_B->bottom->next = tmp;
	tmp->prev = list_B->bottom;
	tmp->next = list_B->top;
	list_B->top = tmp;
	printf("-------pb\n");
	display_list(list_A);
	printf("=======list B\n");
	display_list(list_B);
}