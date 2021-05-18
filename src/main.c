/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:51:16 by mtak              #+#    #+#             */
/*   Updated: 2021/05/18 21:50:06 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

typedef struct      s_box
{
    t_stack *A;
    t_stack *B;
}                   t_box;

typedef struct      s_stack
{
    t_node *top;
    t_node *bottom;

}                   t_stack;

typedef struct      s_node
{
    t_node  *prev;
    t_node  *next;
    int     num;
}                   t_node;


void exit_error(struct t_node *A, struct t_node *B, char const *err_msg)
{
    free_machine(A);
    free_machine(B);
    write(1, err_msg, ft_strlen(err_msg));
    exit(EXIT_FAILURE);
}

void sort_stack(struct t_node *A, struct t_node *B)
{

}

t_node		*lstnew(int *content)
{
	t_node	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->num = content;
	new_node->next = NULL;
	return (new_node);
}
t_node *add_first(t_node *head, int c)
{
    t_node *newNode;
    
    newNode= (t_node *)malloc(sizeof(t_node));
    newNode->next = head->next;
    newNode->num = c;
    head->next = newNode;
    return newNode;
}
int init_stack(t_box *box, char **av, int len_list)
{  
    t_node *top;
    t_node *bottom;
    t_node *node;

    if (!(box->A = (t_stack *)malloc(sizeof(t_stack))))
        return NULL;
    
    top = (t_node *)malloc(sizeof(t_node));
    top->next = NULL;
    bottom = (t_node *)malloc(sizeof(t_node));
    bottom = add_first(top, ft_atoi(av[len_list]));
    while(--len_list > 0)
        add_first(top, ft_atoi(av[len_list]));
    box->A->top = top;
     return (exit_err(&A, &B, "Error\nFailed to alloc stack\n"));
}

int init_box(t_box *box, char ** av, int ag)
{
    if (!(box = (t_box *)malloc(sizeof(t_box))))
        return NULL;
    if (!init_stack(box, av, ag ))
        return NULL;
    
}

int main(int ag, char **av)
{
    t_box box;

    init_box(&box, (char **)av, ag - 1);

   
    if (check_error(box.A, box.B))
        return (exit_err(box.A, box.B, "Error\nInvalid Stack\n"));
    sort_stack(box.A, box.B);
    return (EXIT_SUCCESS);
}