/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:55:36 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 12:43:31 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack *stack_1, t_stack *stack_2)
{
	int	min;
	int	count_rotations;

	min = find_min_value(stack_1, 4);
	count_rotations = 0;
	while (stack_1->stack[0] != min)
	{
		rotate(stack_1);
		count_rotations++;
	}
	push(stack_1, stack_2);
	while (count_rotations)
	{
		reverse_rotate(stack_1);
		count_rotations--;
	}
	sort_top_three(stack_1, stack_2, 3);
	push(stack_2, stack_1);
}

void	sort_five(t_stack *stack_1, t_stack *stack_2)
{
	int	min;
	int	count_rotations;

	min = find_min_value(stack_1, 5);
	count_rotations = 0;
	while (stack_1->stack[0] != min)
	{
		rotate(stack_1);
		count_rotations++;
	}
	push(stack_1, stack_2);
	while (count_rotations)
	{
		reverse_rotate(stack_1);
		count_rotations--;
	}
	sort_four(stack_1, stack_2);
	push(stack_2, stack_1);
}

void	sort_top_five(t_stack *stack_1, t_stack *stack_2, int counter)
{
	if (counter <= 3)
	{
		sort_top_three(stack_1, stack_2, counter);
	}
	else if (counter == 4)
	{
		sort_four(stack_1, stack_2);
	}
	else if (counter == 5)
	{
		sort_five(stack_1, stack_2);
	}
}
