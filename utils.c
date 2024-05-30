/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:34:24 by anarama           #+#    #+#             */
/*   Updated: 2024/05/27 11:42:13 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		ft_printf("%d\n", stack->stack[i]);
		i++;
	}
}

void	print_stacks(t_stack *stack_1, t_stack *stack_2)
{
	ft_printf("---------------\n");
	ft_printf("STACK %c:\n", stack_1->name);
	print_stack(stack_1);
	ft_printf("STACK %c:\n", stack_2->name);
	print_stack(stack_2);
	ft_printf("---------------\n");
}

void	initalise_stacks(char ***input, int *stack_a, int *index_stack_a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			stack_a[k] = ft_atoi(input[i][j]);
			index_stack_a[k] = k;
			check_input(input[i][j], stack_a[k], input, stack_a);
			j++;
			k++;
		}
		i++;
	}
}

int	create_stack_a(char ***input, t_stack *a)
{
	static int	*index_stack_a = NULL;

	a->stack = malloc(sizeof(int) * a->len);
	index_stack_a = malloc(sizeof(int) * a->len);
	if (!a->stack || !index_stack_a)
	{
		free(a->stack);
		free(index_stack_a);
		free_input(input);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initalise_stacks(input, a->stack, index_stack_a);
	free_input(input);
	make_indices_arr(a->stack, index_stack_a, a->len);
	free(a->stack);
	a->stack = index_stack_a;
	return (0);
}

int	get_stack_a(t_stack *a, int argc, char **argv)
{
	char	***input;
	int		i;

	i = 0;
	input = ft_calloc(sizeof(char **), argc);
	if (!input)
		return (1);
	while (i < argc - 1)
	{
		input[i] = ft_split(argv[i + 1], ' ');
		if (!input[i])
			free_input(input);
		a->len += array_len(input[i]);
		i++;
	}
	input[i] = NULL;
	return (create_stack_a(input, a));
}
