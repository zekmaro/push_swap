/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_hex_lower.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:54:12 by anarama           #+#    #+#             */
/*   Updated: 2024/05/01 20:14:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_hex_lower(size_t n, int fd, int *counter)
{
	if (n >= 16)
		ft_putnbr_fd_hex_lower(n / 16, fd, counter);
	if (n % 16 >= 10)
		ft_printchar_fd((n % 16) - 10 + 'a', fd, counter);
	else
		ft_printchar_fd((n % 16) + '0', fd, counter);
}
