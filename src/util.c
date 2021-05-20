/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:35:52 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:42:33 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int is_num(char *str)
{
	while (*str)
	{
		if (!('0' < *str && *str <= '9'))
			return (EXIT_FAILED);
		str++;
	}
	return (EXIT_SUCCESSED);
}

void display_list(t_stack *list)
{
	t_node *node;

	node = list->top;
	printf("%d\n", node->data);
	node = node->next;
	while (node != list->top)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}

int	is_duplicate(t_node *element, t_stack *list)
{

	return (EXIT_SUCCESSED);
}

int add_node(t_stack *list, int position, t_node *element)
{
	t_node *new_node;
	t_node *pre_node;
	int i;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (EXIT_FAILED);
	pre_node = list->bottom;
	if (!list->cnt_idx && is_duplicate(element->data, list))
		return (EXIT_FAILED);
	new_node->data = element->data;
	if (list->cnt_idx == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		list->bottom = new_node;
	}
	else
	{
		i = -1;
		while (++i < position)
			pre_node = pre_node->next;
		new_node->next = pre_node->next;
		new_node->prev = pre_node;
		pre_node->next = new_node;
		new_node->next->prev = new_node;
		if (position == list->cnt_idx)
			list->bottom = new_node;
	}
	list->cnt_idx++;
	return (EXIT_SUCCESSED);
}