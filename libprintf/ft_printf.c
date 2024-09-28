/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:51:53 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:51:55 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		nprint;
	int		n_format;

	nprint = 0;
	n_format = 0;
	va_start(ap, str);
	while (str[nprint])
	{
		if (str[nprint] == '%')
			n_format += format_code(&str[++nprint], ap);
		else
			n_format += ft_putchar_fd(str[nprint], FD);
		nprint++;
	}
	va_end(ap);
	return (n_format--);
}
