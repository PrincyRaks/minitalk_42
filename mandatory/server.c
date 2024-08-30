/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:49:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/30 16:32:48 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_message;

char	*strjoin_data(char *s1, char c)
{
	char	*new_s;
	char	*tmp_s1;
	int		len;

	len = ft_strlen(s1) + 1;
	new_s = (char *)malloc(sizeof(char) * len + 1);
	if (!new_s)
	{
		free(s1);
		return (NULL);
	}
	tmp_s1 = s1;
	printf("%s\n", tmp_s1);
	while (tmp_s1 != NULL && *tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (c)
		*(new_s++) = c;
	*(new_s++) = 0;
	if (s1 != NULL)
		free(s1);
	return (new_s - len);
}

void	display_msg(char *message)
{
	ft_putstr_fd(message, 1);
	free(message);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)context;
	c = (c << 1) | (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			display_msg(g_message);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		g_message = strjoin_data(g_message, c);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_server;
	// int					check_sigaction;

	ft_putstr_fd("======= SERVER RUNNING 🚀\n", 1);
	ft_putstr_fd("PID => ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa_server.sa_sigaction = signal_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	// if (check_sigaction == -1)
	// 	exit (1);
	while (1)
	{
	}
	return (0);
}
