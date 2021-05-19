/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:52:19 by mtak              #+#    #+#             */
/*   Updated: 2021/05/19 15:42:49 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct      s_node
{
	struct s_node  *prev;
	struct s_node  *next;
	int     data;
}                   t_node;

typedef struct      s_stack
{
	int		cnt_idx;
	t_node	*top;
	t_node	*bottom;

}                   t_stack;

typedef struct      s_box
{
	t_stack *A;
	t_stack *B;
}                   t_box;

#define EXIT_SUCCESSED 1
#define EXIT_FAILED 0

#endif