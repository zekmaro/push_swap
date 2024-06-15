/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:42:18 by anarama           #+#    #+#             */
/*   Updated: 2024/06/14 11:46:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//----HEADERS----
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
//---------------

//----STRUCT-----
typedef struct stack
{
	int		*stack;
	int		len;
	char	name;
}	t_stack;
//---------------

//-----UTILS-----
int		array_len(char **str);
void	free_memory(char **arr);
void	free_input(char ***arr);
int		ft_realloc(t_stack *stack, int new_size);
int		calculate_pivot(int size);
int		find_min_value(t_stack *stack, int range);
int		find_max_value(t_stack *stack, int range);
//---------------

//----UTILS3-----
void	divide_stack(t_stack *stack_1, t_stack *stack_2, int pivot);
int		find_cost(int index, t_stack *stack_b);
int		find_index(int num, t_stack *stack_b);
int		get_min_cost_index(int num, t_stack *stack_b);
//---------------

//----UTILS4-----
int		put_bottom_a(t_stack *stack_a, t_stack *stack_b, int top_a);
void	push_next_value(int temp_index, t_stack *stack_a, t_stack *stack_b, int	top_a);
void	divide_stack_a(t_stack *stack_a, t_stack *stack_b);
//---------------

//----PARSING----
int		check_input(char *str, int num);
void	initalise_stacks(char ***input, int *stack_a, int *index_stack_a);
int		get_stack_a(t_stack *a, int argc, char **argv);
//---------------

//---SORTING-----
int		bubblesort(int *arr, int n);
int		*copy_arr(int *arr, int len);
void	make_indices_arr(int *arr, int *indices, int n);
void	sort_swap(int *x, int *y);
void	sort_three(int *stack, char name_stack);
void	sort_top_three(t_stack *stack_1, t_stack *stack_2, int counter);
void	sort_top_five(t_stack *stack_1, t_stack *stack_2, int counter);
int		check_sorted_reversed(t_stack *stack_id);
int		check_sorted(t_stack *stack_id);
void	sort_fast(t_stack *stack_a, t_stack *stack_b);
//---------------

//----METHODS----
void	swap(t_stack *stack_id);
void	rotate(t_stack *stack_id);
void	reverse_rotate(t_stack *stack_id);
void	push(t_stack *src, t_stack	*dest);

//---BONUS_METHODS---
void	swap_bonus(t_stack *stack_id);
void	rotate_bonus(t_stack *stack_id);
void	reverse_rotate_bonus(t_stack *stack_id);
void	push_bonus(t_stack *src, t_stack *dest, char **str);

#endif