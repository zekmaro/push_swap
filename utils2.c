/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:46:13 by anarama           #+#    #+#             */
/*   Updated: 2024/06/14 13:38:29 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_reversed(t_stack *stack_id)
{
	int	i;

	i = 0;
	while (i < stack_id->len - 1)
	{
		if ((stack_id->stack[i] - stack_id->stack[i + 1]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted(t_stack *stack_id)
{
	int	i;

	i = 0;
	while (i < stack_id->len - 1)
	{
		if ((stack_id->stack[i + 1] - stack_id->stack[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	calculate_pivot(int size)
{
	int	i;

	i = 1;
	while (i * i < size / 2)
		i++;
	if (size <= 50)
	{
		if (size % 2 == 0)
			return (size / 2);
		else if (size % 2 == 1)
			return (size / 2 + 1);
	}
	else if (size > 50 && size <= 100)
	{
		return (i * 4);
	}
	return (i * 5);
}

int	find_min_value(t_stack *stack, int range)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack[0];
	while (i < range)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	find_max_value(t_stack *stack, int range)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack[0];
	while (i < range)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}
