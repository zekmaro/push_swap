/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:20:48 by anarama           #+#    #+#             */
/*   Updated: 2024/05/01 20:17:19 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	fill_specifiers(char *specifiers)
{
	ft_memcpy(specifiers, "cspdiuxX", 8);
	specifiers[8] = '%';
	specifiers[9] = '\0';
}

int	handle_specifiers(const char **str, va_list args,
					char *specifiers, int *counter)
{
	(*str)++;
	if (ft_strchr(specifiers, **str))
	{
		if (**str == 'c')
			ft_printchar_fd((char)va_arg(args, int), 1, counter);
		else if (**str == 's')
			ft_printstr_fd(va_arg(args, char *), 1, counter);
		else if (**str == 'p')
			ft_putnbr_fd_ptr((size_t)va_arg(args, void *), 1, counter, 1);
		else if (**str == 'd' || **str == 'i')
			ft_putnbr_fd_dec(va_arg(args, int), 1, counter);
		else if (**str == 'u')
			ft_putnbr_fd_uns(va_arg(args, unsigned int), 1, counter);
		else if (**str == 'x')
			ft_putnbr_fd_hex_lower(va_arg(args, unsigned int), 1, counter);
		else if (**str == 'X')
			ft_putnbr_fd_hex_upper(va_arg(args, unsigned int), 1, counter);
		else if (**str == '%')
			ft_printchar_fd('%', 1, counter);
		(*str)++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	char		specifiers[10];
	int			counter;

	if (str == NULL)
		return (-1);
	counter = 0;
	fill_specifiers(specifiers);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (handle_specifiers(&str, args, specifiers, &counter))
				continue ;
			write(1, &specifiers[8], 1);
		}
		ft_printchar_fd(*str, 1, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
