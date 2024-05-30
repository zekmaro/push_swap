/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:59:52 by anarama           #+#    #+#             */
/*   Updated: 2024/05/30 18:00:41 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack(t_stack *stack_1, t_stack *stack_2, int pivot)
{
	int next_pivot;
	int save;
	int min;
	int i;
	
	save = stack_1->len;
	min = find_min_value(stack_1, stack_1->len);
	next_pivot = (min + pivot) / 2;
	i = 0;
	while (i < save && stack_1->len > 3)
	{
		if (stack_1->stack[0] >= pivot)
		{
			rotate(stack_1);	
		}
		else if (stack_1->stack[0] < pivot)
		{
			push(stack_1, stack_2);
			if (stack_2->stack[0] <= next_pivot)
				rotate(stack_2);
		}
		i++;
	}
}

int	find_cost(int index, t_stack *stack_b)
{
	int	cost;

	cost = 0;
	if (index <= stack_b->len / 2)
	{
		cost = index + 1;
	}
	else 
	{
		cost = stack_b->len + 1 - index;
	}
	return (cost);
}
int find_index(int num, t_stack *stack_b)
{
	int i;

	i = 0;
	while (i < stack_b->len)
	{
		if (stack_b->stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	get_min_cost_index(int num, t_stack *stack_b)
{
	int temp;
	int temp_cost;
	int	min_cost;
	int i;
	int save;

	save = -1;
	min_cost = stack_b->len + 1;
	i = 0;
	while (i < 3)
	{
		temp = find_index(num - 1 - i, stack_b);
		if (temp == -1)
		{
			i++;
			continue ;
		}
		temp_cost = find_cost(temp, stack_b);
		if (temp_cost <= min_cost)
		{
			min_cost = temp_cost;
			save = temp;
		}
		i++;
	}
	return (save);
}