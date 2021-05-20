/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:32:03 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:42:10 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/* int	is_av_valid(int i, t_stack *list)
{
	t_node *node;

	node = 
	
} */



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
	i = 0;
	while (i < len_list)
	{
		if (!is_num(&av[i]))
			return (EXIT_FAILED);
		node->data = ft_atoi(av[i + 1]);
		printf("데이터 순서: %d\n", node->data);
		add_node(box->A, i, node);
		i++;
	}
	i = 0;
	while (i< len_list)
	{
		node->data = 0;
		add_node(box->B, i, node);
		i++;
	}
	box->A->top = box->A->bottom->next;
	box->B->top = box->B->bottom->next;
	display_list(box->A);
	return (EXIT_SUCCESSED);
}

int init_box(t_box *box, char ** av, int len_list)
{
	if (!(box = (t_box *)malloc(sizeof(t_box))))
		return NULL;
	if (!init_stack(box, av, len_list))
		return NULL;
	return 0;
}