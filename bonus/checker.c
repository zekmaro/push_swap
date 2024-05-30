/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:54:25 by anarama           #+#    #+#             */
/*   Updated: 2024/05/30 17:57:43 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_double_rotations(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(str, "rr", 2) == 0)
	{
		rotate_bonus(stack_a);
		rotate_bonus(stack_b);
	}
	else if (ft_strncmp(str, "rrr", 3) == 0)
	{
		reverse_rotate_bonus(stack_a);
		reverse_rotate_bonus(stack_b);
	}
}

void	check_operation(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(str, "pb", 2) == 0)
		push_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "pa", 2) == 0)
		push_bonus(stack_b, stack_a);
	else if (ft_strncmp(str, "sa", 2) == 0)
		swap_bonus(stack_a);
	else if (ft_strncmp(str, "sb", 2) == 0)
		swap_bonus(stack_b);
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate_bonus(stack_a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate_bonus(stack_b);
	else if (ft_strncmp(str, "rra", 3) == 0)
		reverse_rotate_bonus(stack_a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		reverse_rotate_bonus(stack_b);
	else
		check_double_rotations(str, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	ft_bzero(&stack_a, sizeof(t_stack));
	ft_bzero(&stack_b, sizeof(t_stack));
	stack_a.name = 'a';
	stack_b.name = 'b';
	get_stack_a(&stack_a, argc, &argv[0]);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_operation(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (check_sorted(&stack_a) && stack_b.len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stack_a.stack);
	free(stack_b.stack);
}
