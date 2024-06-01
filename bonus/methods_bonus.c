/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:53:04 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 13:38:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_bonus(t_stack *stack_id)
{
	if (stack_id->len < 2)
	{
		return ;
	}
	sort_swap(stack_id->stack, stack_id->stack + 1);
}

void	rotate_bonus(t_stack *stack_id)
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
}

// rotate down
void	reverse_rotate_bonus(t_stack *stack_id)
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
}

void	free_stacks_bonus(t_stack *stack_1, t_stack *stack_2)
{
	free(stack_1->stack);
	free(stack_2->stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	push_bonus(t_stack *src, t_stack *dest)
{
	int	status;

	if (src->len == 0)
	{
		return ;
	}
	status = ft_realloc(dest, dest->len + 1);
	if (status == 1)
	{
		free_stacks_bonus(src, dest);
	}
	dest->stack[0] = src->stack[0];
	status = ft_realloc(src, src->len - 1);
	if (status == 1)
	{
		free_stacks_bonus(src, dest);
	}
}
