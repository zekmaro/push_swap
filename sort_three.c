/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:02 by anarama           #+#    #+#             */
/*   Updated: 2024/05/30 11:51:33 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_sa_pa_sa(t_stack *stack_1, t_stack *stack_2)
{
	push(stack_1, stack_2);
	swap(stack_1);
	push(stack_2, stack_1);
	swap(stack_1);
}

void	pb_sa_pa(t_stack *stack_1, t_stack *stack_2)
{
	push(stack_1, stack_2);
	swap(stack_1);
	push(stack_2, stack_1);
}

void	sa_pb_sa_pa(t_stack *stack_1, t_stack *stack_2)
{
	swap(stack_1);
	push(stack_1, stack_2);
	swap(stack_1);
	push(stack_2, stack_1);
}

void	final_sort(t_stack *stack_1, t_stack *stack_2)
{
	int first;
	int middle;
	int last;

	first = stack_1->stack[0];
	middle = stack_1->stack[1];
	last = stack_1->stack[2];
	if (first > middle && middle < last && first < last)
		swap(stack_1);
	else if (first < middle && middle > last && first > last)
		pb_sa_pa_sa(stack_1, stack_2);
	else if (first < middle && middle > last && first < last)
		pb_sa_pa(stack_1, stack_2);
	else if (first > middle && middle < last && first > last)
		sa_pb_sa_pa(stack_1, stack_2);
	else if (first > middle && middle > last)
	{
		swap(stack_1);
		pb_sa_pa_sa(stack_1, stack_2);
	}
}

void	sort_top_three(t_stack *stack_1, t_stack *stack_2, int counter)
{
	if (counter == 1)
		return ;
	if (counter == 2)
	{
		if (stack_1->stack[0] > stack_1->stack[1])
			swap(stack_1);
		return ;
	}
	final_sort(stack_1, stack_2);
}