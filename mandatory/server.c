/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:49:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/26 15:35:35 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_util	*g_response = NULL;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

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
				print_error_sig();
		}
		if (c == 0)
		{
			print_response(&g_response, info->si_pid);
			exit(0);
		}
		g_response->tail->message[g_response->tail->n_used] = c;
		g_response->tail->n_used++;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	struct sigaction	sa_server;

	if (argc != 1)
		print_err_server();
	ft_putstr_fd("======= SERVER IS RUNNING 🚀\nPID => ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa_server.sa_sigaction = &signal_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1)
		print_error_sig();
	if (sigaction(SIGUSR2, &sa_server, NULL) == -1)
		print_error_sig();
	while (1)
		;
	return (0);
}
