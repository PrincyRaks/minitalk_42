/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:03:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/26 16:03:13 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	format_code(const char *str, va_list ap)
{
	int	n_format;

	n_format = 0;
	if (*str == 'c')
		n_format = ft_putchar_fd(va_arg(ap, int), FD);
	else if (*str == 's')
		n_format = ft_putstr_fd(va_arg(ap, char *), FD);
	else if (*str == 'p')
		n_format = ft_print_hexa(va_arg(ap, unsigned long), *str);
	else if (*str == 'd' || *str == 'i')
		n_format = ft_putnbr_int(va_arg(ap, int));
	else if (*str == 'u')
		n_format = ft_putnbr_uint(va_arg(ap, unsigned int));
	else if (*str == 'x' || *str == 'X')
		n_format = ft_print_hexa(va_arg(ap, unsigned int), *str);
	else
		n_format = ft_putchar_fd('%', FD);
	return (n_format);
}
