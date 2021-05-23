/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:37:54 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 19:59:39 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void rrb(t_stack  *list)
{
	t_node *tmp;
	
	tmp = list->bottom;
	list->top = list->bottom;
	list->bottom = tmp->prev;
	printf("------rrb\n");
	display_list(list);
}

void rra(t_stack  *list)
{
	t_node *tmp;
	
	tmp = list->bottom;
	list->top = list->bottom;
	list->bottom = tmp->prev;
	printf("-------rra\n");
	display_list(list);
}
void rrr(t_stack *list_A, t_stack *list_B)
{
	rra(list_A);
	rrb(list_B);
}