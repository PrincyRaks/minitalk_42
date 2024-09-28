/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:43:41 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:39:43 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_int(int n)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", FD));
	if (n < 0)
	{
		return (ft_putchar_fd('-', FD) + ft_putnbr_int(-n));
	}
	if (n > 9)
	{
		return (ft_putnbr_int(n / 10) + ft_putnbr_int(n % 10));
	}
	else
		return (ft_putchar_fd(n + '0', FD));
}
