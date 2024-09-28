/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:32:58 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:41:23 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef FD
#  define FD 1
# endif

# include <stdarg.h>
# include "./utils/utils.h"

int	ft_printf(const char *str, ...);
int	format_code(const char *str, va_list ap);

#endif
