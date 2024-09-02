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
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Message is received by server! \n", 1);
		exit(0);
	}
}

void	send_sigbit(int pid, char c)
{
	int	nbits;
	int	bit;

	nbits = 7;
	while (nbits >= 0)
	{
		bit = (c >> nbits) & 1;
		if (bit == 1)
			bit = SIGUSR1;
		else 
			bit = SIGUSR2;
		if (kill(pid, bit) == -1)
			ft_putstr_fd("Error to send signal", 2);
		usleep(45);
		nbits--;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		g_signal = 0;
		send_sigbit(pid, *msg);
		while (!g_signal)
			pause();
		msg++;
	}
	send_sigbit(pid, 0);
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
