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

t_util	*g_response = NULL;

void	print_error(void)
{
	ft_putstr_fd("\033[91mError to send\033[0m", 2);
	exit(1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int					i = 0;
	static char					c = 0;
	(void)context;

	c = (c << 1) | (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!g_response || g_response->tail->n_used == 500)
		{
			new_t_node(&g_response);
			if (!g_response)
				print_error();
		}
		if (c == 0)
		{
			print_response(&g_response, info->si_pid);
			return ;
		}
		g_response->tail->message[g_response->tail->n_used] = c;
		g_response->tail->n_used++;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_server;

	ft_putstr_fd("======= SERVER RUNNING 🚀\n", 1);
	ft_putstr_fd("PID => ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa_server.sa_sigaction = &signal_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1)
		print_error();
	if (sigaction(SIGUSR2, &sa_server, NULL) == -1)
		print_error();
	while (1)
		;
	return (0);
}
