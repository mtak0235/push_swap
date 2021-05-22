/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:35:52 by mtak              #+#    #+#             */
/*   Updated: 2021/05/22 20:46:24 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	is_num(char *av)
{
	char *str;

	str = av;
	while (*av)
	{
		if (!('0' <= *av && *av <= '9'))
			return (EXIT_FAILED);
		av++;
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
	t_node *node;

	node = list->bottom->next;
	if (node->data == element->data)
		return (EXIT_SUCCESSED);
	node = node->next;
	while (node != list->bottom->next)
	{
		if (node->data == element->data)
			return (EXIT_SUCCESSED);
		node = node->next;
	}
	return (EXIT_FAILED);
}

int add_node(t_stack *list, int position, t_node *element)
{
	t_node *new_node;
	t_node *pre_node;
	int i;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (EXIT_FAILED);
	if (list->cnt_idx && is_duplicate(element, list))
		return (EXIT_FAILED);
	pre_node = list->bottom;
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