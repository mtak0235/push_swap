/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:52:19 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:35:54 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct		s_node
{
	struct s_node  *prev;
	struct s_node  *next;
	int     data;
}					t_node;

typedef struct 		s_stack
{
	int		cnt_idx;
	t_node	*top;
	t_node	*bottom;

}					t_stack;

typedef struct		s_box
{
	t_stack *A;
	t_stack *B;
}					t_box;

#define EXIT_SUCCESSED 1
#define EXIT_FAILED 0

/* action */
void ra(t_stack *list);
void rb(t_stack *list);
void rr(t_stack *list_A, t_stack *list_B);
void sb(t_stack *list);
void sa(t_stack *list);
void ss(t_stack *list_A, t_stack *list_B);
void rrb(t_stack  *list);
void rra(t_stack  *list);
void rrr(t_stack *list_A, t_stack *list_B);
void pa(t_stack *list_B, t_stack *list_A);
void pb(t_stack *list_A, t_stack *list_B);

/* util */
void display_list(t_stack *list);
int add_node(t_stack *list, int position, t_node *element);

/* init */
int init_stack(t_box *box, char **av, int len_list);
int init_box(t_box *box, char ** av, int len_list);

/* util */
void display_list(t_stack *list);
#endif