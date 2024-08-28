/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:49:24 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/26 16:10:09 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*g_message;

char	*strjoin_data(char *s1, char c)
{
	char	*new_s;
	char	*tmp_s1;

	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!new_s)
		return (free(s1), NULL);
	tmp_s1 = s1;
	while (*tmp_s1)
		*(new_s++) = *(tmp_s1++);
	if (c)
		*(new_s++) = c;
	*(new_s++) = 0;
	free(s1);
	return (new_s - len);
}

void	signal_handler(int signum, siginfo_t* info, void* context)
{
	int	i;
	char c;

	c = c << 1 | (signum == SIGUSR1);
	i++;
	kill(info->si_pid, SIGUSR1);
	if (i == 7)
	{
		if (c == 0)
		{
			ft_putstr_fd(g_message, 1);
			free(g_message);
			return ;
		}
		g_message = strjoin_data(g_message, c);
	}
	kill(info.si_pid, SIGUSR1);
}



int	main(void)
{
	ft_putstr_fd("server PID 🚀:", getpid());
	struct sigaction sa_server;

	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	while (1)
		pause();
	return (0);
}