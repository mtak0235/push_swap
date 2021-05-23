/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:20:04 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 20:33:49 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int main(int ag, char **av)
{
	t_box *box;

	box = NULL;
	if (ag < 2)
		return (1);
	if (!(box = init_box(box, (char **)av, ag - 1)))
		return (EXIT_FAILED);
	push_swap(box);
	//free_machine(&box);
	return (EXIT_SUCCESSED);
}