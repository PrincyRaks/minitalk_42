/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:57 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/29 16:42:28 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		g_signal;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_signal = 1;
	// if (signum == SIGUSR2)
	// 	ft_putstr_fd("Message is received by server!", 1);
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
		// printf("%d\n", ((c >> nbits) & 1));
		if ((c >> nbits) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		// if (kill(pid, SIGUSR1) == -1)
		// 	exit(1);
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
	int	pid;

	if (argc != 3)
		print_error_arg();
	if (!check_pid(argv[1]))
		print_error_arg();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	return (0);
}
