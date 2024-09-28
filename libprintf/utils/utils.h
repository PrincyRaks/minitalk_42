/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:47:00 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:39:59 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef FD
#  define FD 1
# endif

# include <stddef.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(unsigned long l, char *base);
int		ft_print_hexa(unsigned long l, char format_hexa);
int		ft_putnbr_uint(unsigned int n);
int		ft_putnbr_int(int n);

#endif
