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

t_list	*g_response = NULL;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	(void)context;

	c = (c << 1) | (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!g_response)
			g_response = new_t_list(&g_response);
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR2);
			add_lstresponse(g_response);
			free_list(&g_response->head);
			return ;
		}
		if (g_response->n_used == 500)
			g_response = new_t_list(&g_response);	
		g_response->message[g_response->n_used] = c;
		g_response->n_used++;
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
		ft_putstr_fd("Error to send signal", 2);
	if (sigaction(SIGUSR2, &sa_server, NULL) == -1)
		ft_putstr_fd("Error to send signal", 2);
	while (1)
		;
	return (0);
}
