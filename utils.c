/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:34:24 by anarama           #+#    #+#             */
/*   Updated: 2024/06/11 14:46:11 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(char ***input, int *stack_a, int *index_stack_a)
{
	free(stack_a);
	free(index_stack_a);
	free_input(input);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
		if (!input[i][j])
			free_and_exit(input, stack_a, index_stack_a);
		while (input[i][j])
		{
			stack_a[k] = ft_atoi(input[i][j]);
			index_stack_a[k] = k;
			if (!check_input(input[i][j], stack_a[k]))
				free_and_exit(input, stack_a, index_stack_a);
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
		{
			free_input(input);
			return (1);
		}
		a->len += array_len(input[i]);
		i++;
	}
	input[i] = NULL;
	return (create_stack_a(input, a));
}
