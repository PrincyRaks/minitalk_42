/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:47:25 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/01 22:17:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error_arg(void)
{
	ft_putstr_fd("ERROR: Wrong format ! please insert this way: \n", 1);
	ft_putstr_fd("./client <PID> [message] \n", 1);
	exit(1);
}

int	check_pid(char *argv)
{
	while (*argv)
	{
		if (ft_isdigit(*argv) == 0)
			return (0);
		argv++;
	}
	return (1);
}

char	*strjoin_data(char *s1, char c)
{
	char	*new_s;
	char	*tmp_s1;
	int		len;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	len = ft_strlen(s1) + 1;
	new_s = ft_calloc(1, (len + 1));
	if (!new_s)
	{
		free(s1);
		return (NULL);
	}
	tmp_s1 = s1;
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (c)
		*(new_s++) = c;
	free(s1);
	return (new_s - len);
}
