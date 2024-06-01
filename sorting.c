/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:13:45 by anarama           #+#    #+#             */
/*   Updated: 2024/06/01 13:59:34 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(int *arr, int *indices, int *copy)
{
	free(arr);
	free(indices);
	free(copy);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	sort_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	bubblesort(int *arr, int n)
{
	int	i;
	int	j;
	int	found_dup;

	found_dup = 0;
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] == arr[j + 1])
				found_dup = 1;
			if (arr[j] > arr[j + 1])
			{
				sort_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (found_dup);
}

int	*copy_arr(int *arr, int len)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

void	make_indices_arr(int *arr, int *indices, int n)
{
	int	i;
	int	j;
	int	*copy;

	i = 0;
	copy = copy_arr(arr, n);
	if (!copy || bubblesort(arr, n))
		free_arr(arr, indices, copy);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (copy[i] == arr[j])
			{
				indices[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
