/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:57 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/30 15:31:55 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_signal;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_signal = 1;
	if (signum == SIGUSR2)
		ft_putstr_fd("Message is received by server!", 1);
}

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

void	send_sigbit(int pid, char c)
{
	int	nbits;

	nbits = 7;
	while (nbits >= 0)
	{
		while (!g_signal)
			pause();
		if ((c >> nbits) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				printf("ERROR sig1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				printf("ERROR sig2");
		}
		nbits--;
		g_signal = 0;
	}
}

void	send_msg(int pid, char *msg)
{
	if (*msg)
		g_signal = 1;
	while (*msg)
	{
		send_sigbit(pid, *msg);
		msg++;
	}
	send_sigbit(pid, '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		print_error_arg();
	if (!check_pid(argv[1]))
		print_error_arg();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
