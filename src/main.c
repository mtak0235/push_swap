/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:20:04 by mtak              #+#    #+#             */
/*   Updated: 2021/05/19 18:19:52 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

 /* void exit_error(struct t_node *A, struct t_node *B, char const *err_msg)
{
	free_machine(A);
	free_machine(B);
	write(1, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILED);
}

void sort_stack(struct t_node *A, struct t_node *B)
{
} */

void pb(t_stack *list_B, t_stack *list_A)
{
	t_node *tmp;

	tmp = list_A->top;
	list_A->bottom->next = list_A->top->next;
	tmp->next->prev = tmp->prev;
	list_A->top = tmp->next;

	tmp->next = list_B->top;
	tmp->prev = list_B->bottom;
	list_B->bottom->next = tmp;
	list_B->top->prev = tmp;
}
void pa(t_stack *list_A, t_stack *list_B)
{
	t_node *tmp;

	tmp = list_B->top;
	list_B->bottom->next = list_B->top->next;
	tmp->next->prev = tmp->prev;
	list_B->top = tmp->next;

	tmp->next = list_A->top;
	tmp->prev = list_A->bottom;
	list_A->bottom->next = tmp;
	list_A->top->prev = tmp;
}

void rrb(t_stack  *list)
{
	t_node *tmp;
	
	tmp = list->bottom;
	list->top = list->bottom;
	list->bottom = tmp->prev;
}

void rra(t_stack  *list)
{
	t_node *tmp;
	
	tmp = list->bottom;
	list->top = list->bottom;
	list->bottom = tmp->prev;
}
void rrr(t_stack *list_A, t_stack *list_B)
{
	rra(list_A);
	rrb(list_B);
}

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

void display_list(t_stack *list)
{
	int i;
	t_node *node;

	i = -1;
	node = list->bottom->next;
	while (++i < list->cnt_idx)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}
int add_node(t_stack *list, int position, t_node *element)
{
	t_node *new_node;
	t_node *pre_node;
	int i;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
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

int init_stack(t_box *box, char **av, int len_list)
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
		node->data = ft_atoi(av[i + 1]);
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

	//ss(box->A, box->B);
	pb(box->B, box->A);


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

int main(int ag, char **av)
{
	t_box box;

	init_box(&box, (char **)av, ag - 1);
   
	/* if (check_error(box.A, box.B))
		return (exit_err(box.A, box.B, "Error\nInvalid Stack\n"));
	sort_stack(box.A, box.B); */
	return (EXIT_SUCCESSED);
}