/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:47 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:06:00 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void sb(t_stack *list)
{
	int tmp;

	tmp = list->top->data;
	list->top->data = list->top->next->data;
	list->top->next->data = tmp;
}

void sa(t_stack *list)
{
	int tmp;

	tmp = list->top->data;
	list->top->data = list->top->next->data;
	list->top->next->data = tmp;
}
void ss(t_stack *list_A, t_stack *list_B)
{
	sa(list_A);
	sb(list_B);
}