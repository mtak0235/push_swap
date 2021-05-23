/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:28:57 by mtak              #+#    #+#             */
/*   Updated: 2021/05/23 20:24:41 by mtak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void align_frontier_r_b(t_stack *list, t_stack *list_B, int r)
{
	if (r == 2)
	{
		if (list->top->turn < list->top->next->turn)
			sb(list);
		return ;
	}
	else if (r == 3)
	{
		if (list->top->turn == 1 && list->top->next->turn > list->top->next->next->turn)
		{
			sb(list);
			rra(list);
		}
		else if (list->top->turn == 1)
			rb(list);
		if (list->top->turn == 2)
			(list->top->next->turn > list->top->next->next->turn) ?
			sb(list) : rrb(list);
		if (list->top->turn == 3 && list->top->next->turn < list->top->next->next->turn)
		{
			sb(list);
			rb(list);
		}
	}
	while (r--)
		pa(list_B, list);
}
void align_frontier_r_a(t_stack *list, int r)
{
	if (r == 2)
	{
		if (list->top->turn > list->top->next->turn)
			sa(list);
		return ;
	}
	else if (r == 3)
	{
		if (list->top->turn == 1 && list->top->next->turn > list->top->next->next->turn)
		{
			sa(list);
			ra(list);
		}
		else if (list->top->turn == 2)
			(list->top->next->turn > list->top->next->next->turn) ?
			rra(list) : sa(list);
		else if (list->top->turn == 3 && list->top->next->turn < list->top->next->next->turn)
			ra(list);
		else if (list->top->turn == 3)
		{
			sa(list);
			rra(list);
		}
	}
}

void b2a(t_stack *list_A, t_stack *list_B, int r)
{
	int i;
	int ra_cnt;
	int pa_cnt;
	int rb_cnt;

	if (r <= 3)
		return (align_frontier_r_b(list_A, list_B, r));
	find_pivot(list_B, r);
	printf("piv:%d , %d\n", list_B->pivot_small, list_B->pivot_big);
	i = 0;
	ra_cnt = 0;
	pa_cnt = 0;
	rb_cnt = 0;
	while (i < r)
	{
		if (list_B->top->turn < list_B->pivot_small)
		{
			rb(list_B);
			rb_cnt++;
		}
		else
		{
			pa(list_B, list_A);
			pa_cnt++;
			if (list_A->top->turn >= list_B->pivot_big)
			{
				ra(list_A);
				ra_cnt++;
			}
		}
		i++;
	}
	a2b(list_A, list_B, pa_cnt - ra_cnt);
	i = -1;
	while (rb_cnt != r - pa_cnt && ++i < rb_cnt)
		rrb(list_B);
	i = -1;
	while (++i <= ra_cnt)
		rra(list_A);
	a2b(list_A, list_B, rb_cnt);
	b2a(list_A, list_B, ra_cnt);
}

void a2b(t_stack *list_A, t_stack *list_B, int r)
{
	int i;
	int ra_cnt;
	int pb_cnt;
	int rb_cnt;

	if (r <= 3)
		return (align_frontier_r_a(list_A, r)); /* A에서 앞의  r개를 적절히 정렬해라 */
	find_pivot(list_A, r);
	printf("piv:%d , %d\n", list_A->pivot_small, list_A->pivot_big);
	i = 0;
	ra_cnt = 0;
	pb_cnt = 0;
	rb_cnt = 0;
	while (i < r)
	{
		if (list_A->top->turn >= list_A->pivot_big)
		{
			ra(list_A);
			ra_cnt++;
		}
		else
		{
			pb(list_A, list_B);
			pb_cnt++;
			if (list_B->top->turn >= list_A->pivot_small)
			{
				rb(list_B);
				rb_cnt++;
			}
		}
		i++;
	}
	i = -1;
	while (ra_cnt != r - pb_cnt && ++i < ra_cnt)
		rra(list_A);
	i = -1;
	while (++i <= rb_cnt)
		rrb(list_B);
	a2b(list_A, list_B, ra_cnt);
	b2a(list_A, list_B, rb_cnt);
	b2a(list_A, list_B, pb_cnt - rb_cnt);
}

void push_swap(t_box *box)
{
	find_pivot(box->A, box->A->cnt_idx); //문제 없음
	a2b(box->A, box->B, box->A->cnt_idx);
	//display_list(box->A);
}