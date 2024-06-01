/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:03:36 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 12:59:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_bottom_a(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->stack[stack_a->len - 1] == stack_a->len + stack_b->len - 1)
		|| stack_a->stack[stack_a->len - 1] < stack_b->stack[0])
	{
		push(stack_b, stack_a);
		rotate(stack_a);
		return (1);
	}
	return (0);
}

void	push_next_value(int temp_index, t_stack *stack_a, t_stack *stack_b)
{
	int	save;

	save = stack_b->stack[temp_index];
	if (temp_index <= stack_b->len / 2)
	{
		while (stack_b->stack[0] != save)
		{
			if (!put_bottom_a(stack_a, stack_b))
				rotate(stack_b);
		}
	}
	else if (temp_index > stack_b->len / 2)
	{
		while (stack_b->stack[0] != save)
		{
			if (!put_bottom_a(stack_a, stack_b))
				reverse_rotate(stack_b);
		}
	}
	push(stack_b, stack_a);
}

void	divide_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	max;
	int	min;
	int	i;

	pivot = calculate_pivot(stack_a->len);
	i = 1;
	while (stack_a->len > 3)
	{
		max = find_max_value(stack_a, stack_a->len);
		if (pivot * i > max)
		{
			min = find_min_value(stack_a, stack_a->len);
			divide_stack(stack_a, stack_b, (min + max) / 2);
		}
		else
		{
			divide_stack(stack_a, stack_b, pivot * i);
		}
		i++;
	}
	sort_top_three(stack_a, stack_b, 3);
}
