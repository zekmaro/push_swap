/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:11:31 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 14:16:12 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_len(char **str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	free_memory(char **arr)
{
	char	**temp;

	temp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(temp);
}

void	free_input(char ***arr)
{
	char	***temp;

	temp = arr;
	while (*arr)
	{
		free_memory(*arr);
		arr++;
	}
	free(temp);
}

int	check_input(char *str, int num)
{
	char	*check;

	check = ft_itoa(num);
	if (!check || ft_strncmp(check, str, ft_strlen(str)) != 0)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}

int	ft_realloc(t_stack *stack, int new_size)
{
	int	*new_stack;

	if (!stack->stack)
	{
		stack->stack = ft_calloc(sizeof(int), 1);
		if (!stack->stack)
			return (1);
		stack->len += 1;
		return (0);
	}
	new_stack = ft_calloc(sizeof(int), new_size);
	if (!new_stack)
		return (1);
	if (new_size > stack->len)
	{
		ft_memcpy(new_stack + 1, stack->stack, sizeof(int) * (new_size - 1));
	}
	else if (new_size < stack->len)
	{
		ft_memcpy(new_stack, stack->stack + 1, sizeof(int) * new_size);
	}
	stack->len = new_size;
	free(stack->stack);
	stack->stack = new_stack;
	return (0);
}
