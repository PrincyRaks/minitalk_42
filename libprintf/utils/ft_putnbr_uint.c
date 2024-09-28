/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:43:52 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:39:47 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_uint(unsigned int n)
{
	if (n > 9)
		return (ft_putnbr_uint(n / 10) + ft_putnbr_uint(n % 10));
	else
		return (ft_putchar_fd(n + '0', FD));
}
