/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:30:39 by anarama           #+#    #+#             */
/*   Updated: 2024/06/11 15:28:26 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fast_two(t_stack *stack_a)
{
	int	first;
	int	last;

	first = stack_a->stack[0];
	last = stack_a->stack[2];
	if (last < first)
		swap(stack_a);
}

void	sort_fast_three(t_stack *stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = stack_a->stack[0];
	middle = stack_a->stack[1];
	last = stack_a->stack[2];
	if (first > middle && first < last && middle < last)
		swap(stack_a);
	else if (first < middle && first > last && middle > last)
		reverse_rotate(stack_a);
	else if (first < middle && first < last && middle > last)
	{
		reverse_rotate(stack_a);
		swap(stack_a);
	}
	else if (first > middle && first > last && middle < last)
		rotate(stack_a);
	else if (first > middle && first > last && middle > last)
	{
		rotate(stack_a);
		swap(stack_a);
	}
}

void	sort_fast_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min_value(stack_a, 4);
	while (stack_a->stack[0] != min)
	{
		rotate(stack_a);
	}
	push(stack_a, stack_b);
	sort_fast_three(stack_a);
	push(stack_b, stack_a);
}

void	sort_fast_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min_value(stack_a, 5);
	while (stack_a->stack[0] != min)
	{
		rotate(stack_a);
	}
	push(stack_a, stack_b);
	sort_fast_four(stack_a, stack_b);
	push(stack_b, stack_a);
}

void	sort_fast(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
	{
		sort_fast_two(stack_a);
	}
	else if (stack_a->len == 3)
	{
		sort_fast_three(stack_a);
	}
	else if (stack_a->len == 4)
	{
		sort_fast_four(stack_a, stack_b);
	}
	else if (stack_a->len == 5)
	{
		sort_fast_five(stack_a, stack_b);
	}
}
