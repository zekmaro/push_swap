/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:56:50 by anarama           #+#    #+#             */
/*   Updated: 2024/06/14 13:39:24 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	ft_printf("STACK A\n");
	while (i < stack_a->len)
	{
		ft_printf("%d\n", stack_a->stack[i]);
		i++;
	}
	i = 0;
	ft_printf("STACK B\n");
	while (i < stack_b->len)
	{
		ft_printf("%d\n", stack_b->stack[i]);
		i++;
	}
}

void	restore_order(t_stack *stack_a, t_stack *stack_b, int counter)
{
	if (stack_a->stack[stack_a->len - 1]
		!= stack_a->len - 1)
	{
		while (stack_a->stack[stack_a->len - 1]
			!= stack_a->len + stack_b->len - 1)
		{
			reverse_rotate(stack_a);
			counter++;
		}
		sort_top_five(stack_a, stack_b, counter);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;
	int	temp_index;
	int	top_a;

	divide_stack_a(stack_a, stack_b);
	//print_stacks(stack_a, stack_b);
	while (stack_b->len)
	{
		top_a = stack_a->stack[0];
		counter = 0;
		while (counter < 3 && stack_b->len != 0)
		{
			temp_index = get_min_cost_index(top_a, stack_b);
			if (temp_index == -1)
				reverse_rotate(stack_a);
			else
				push_next_value(temp_index, stack_a, stack_b, top_a);
			counter++;
		}
		sort_top_three(stack_a, stack_b, counter);
		//print_stacks(stack_a, stack_b);
	}
	restore_order(stack_a, stack_b, counter);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;	

	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	stack_a.name = 'a';
	stack_b.name = 'b';
	if (argc == 1)
	{
		return (0);
	}
	if (get_stack_a(&stack_a, argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		get_next_line(-1);
		exit(EXIT_FAILURE);
	}
	if (stack_a.len <= 5 && !check_sorted(&stack_a))
		sort_fast(&stack_a, &stack_b);
	else if (!check_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
