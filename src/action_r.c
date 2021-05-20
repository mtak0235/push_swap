/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:39:07 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:06:08 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void ra(t_stack *list)
{
	t_node *tmp;

	tmp = list->top;
	list->top = tmp->next;
	list->bottom = tmp;
}

void rb(t_stack *list)
{
	t_node *tmp;

	tmp = list->top;
	list->top = tmp->next;
	list->bottom = tmp;
}

void rr(t_stack *list_A, t_stack *list_B)
{
	ra(list_A);
	rb(list_B);
}