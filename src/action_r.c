/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:07 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 19:59:24 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void ra(t_stack *list)
{
	t_node *tmp;

	tmp = list->top;
	list->top = tmp->next;
	list->bottom = tmp;
	printf("-------ra\n");
	display_list(list);
}

void rb(t_stack *list)
{
	t_node *tmp;

	tmp = list->top;
	list->top = tmp->next;
	list->bottom = tmp;
	printf("--------rb\n");
	display_list(list);
}

void rr(t_stack *list_A, t_stack *list_B)
{
	ra(list_A);
	rb(list_B);
}