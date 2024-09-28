/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:53 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:39:40 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_base(unsigned long l, char *base)
{
	int	n_base;

	n_base = ft_strlen(base);
	if (l >= (unsigned long)n_base)
		return (ft_putnbr_base(l / n_base, base) + ft_putnbr_base(l % n_base,
				base));
	else
		return (ft_putchar_fd(base[l], FD));
}
