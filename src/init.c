/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:32:03 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 19:31:39 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"


int	init_stack(t_box *box, char **av, int len_list)
{  
	t_node *node;
	int i;

	if (!((box->A = (t_stack *)malloc(sizeof(t_stack))) && (box->B = (t_stack *)malloc(sizeof(t_stack))) && (node = (t_node *)malloc(sizeof(t_node)))))
		return (EXIT_FAILED);
	box->A->cnt_idx = 0;
	box->B->cnt_idx = 0;
	box->A->bottom = NULL;
	box->A->top = NULL;
	box->B->bottom = NULL;
	box->B->top = NULL;
	i = 1;
	while (i <= len_list)
	{
		if (!is_num(av[i]))
			return (EXIT_FAILED);
		node->data = ft_atoi(av[i]);
		if (!(box->A = add_node(box->A, i - 1, node)))
			return (EXIT_FAILED);
		i++;
	}
	box->A->top = box->A->bottom->next;
	return (EXIT_SUCCESSED);
}

t_box *init_box(t_box *box, char **av, int len_list)
{
	if (!(box = (t_box *)malloc(sizeof(t_box))))
		return (NULL);
	if (!init_stack(box, av, len_list))
		return (NULL);
	return (box);
}