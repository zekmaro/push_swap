/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:57:05 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 13:37:51 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack_id)
{
	if (stack_id->len < 2)
	{
		return ;
	}
	sort_swap(stack_id->stack, stack_id->stack + 1);
	ft_printf("s%c\n", stack_id->name);
}

void	rotate(t_stack *stack_id)
{
	int	i;
	int	first;

	if (stack_id->len < 2)
	{
		return ;
	}
	i = 0;
	first = stack_id->stack[0];
	while (i < stack_id->len - 1)
	{
		stack_id->stack[i] = stack_id->stack[i + 1];
		i++;
	}
	stack_id->stack[stack_id->len - 1] = first;
	ft_printf("r%c\n", stack_id->name);
}

// rotate down
void	reverse_rotate(t_stack *stack_id)
{
	int	i;
	int	last;

	if (stack_id->len < 2)
	{
		return ;
	}
	i = stack_id->len - 1;
	last = stack_id->stack[stack_id->len - 1];
	while (i > 0)
	{
		stack_id->stack[i] = stack_id->stack[i - 1];
		i--;
	}
	stack_id->stack[0] = last;
	ft_printf("rr%c\n", stack_id->name);
}

void	free_stacks(t_stack *stack_1, t_stack *stack_2)
{
	free(stack_1->stack);
	free(stack_2->stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	push(t_stack *src, t_stack *dest)
{
	int	status;

	if (src->len == 0)
	{
		return ;
	}
	status = ft_realloc(dest, dest->len + 1);
	if (status == 1)
	{
		free_stacks(src, dest);
	}
	dest->stack[0] = src->stack[0];
	status = ft_realloc(src, src->len - 1);
	if (status == 1)
	{
		free_stacks(src, dest);
	}
	ft_printf("p%c\n", dest->name);
}
