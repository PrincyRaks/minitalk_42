/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:49:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/29 16:42:43 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (c)
		*(new_s++) = c;
	*(new_s++) = 0;
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
	int		i;
	char	c;

	(void)context;
	c = 0;
	i = 0;
	c = (c << 1) | (signum == SIGUSR1);
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 7)
	{
		if (c == 0)
		{
			display_msg(g_message);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		g_message = strjoin_data(g_message, c);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_server;
	// int					check_sigaction;

	ft_putstr_fd("======= SERVER RUNNING 🚀\n", 1);
	ft_putstr_fd("PID => ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	// if (check_sigaction == -1)
	// 	exit (1);
	while (1)
		pause();
	return (0);
}
