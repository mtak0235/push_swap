/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:20:04 by mtak              #+#    #+#             */
/*   Updated: 2021/05/20 18:41:09 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void exit_error(struct t_node *A, struct t_node *B)
{
	/* free_machine(A);
	free_machine(B); */
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILED);
}

/* void sort_stack(struct t_node *A, struct t_node *B)
{
}  */

int main(int ag, char **av)
{
	t_box box;

	init_box(&box, (char **)av, ag - 1);
	//sort_stack(box.A, box.B);
	return (EXIT_SUCCESSED);
}