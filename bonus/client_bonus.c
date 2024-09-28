/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:39 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:04:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_signal = 0;

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_signal = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("\033[92m✅ Message is received by server!\n\033[0m");
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
		{
			ft_printf("❌ Error sending signal to Server\n");
			exit(1);
		}
		while (!g_signal)
			;
		g_signal = 0;
		nbits--;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_sigbit(pid, *msg);
		msg++;
	}
	send_sigbit(pid, 0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		print_err_client("\t./client_bonus <PID> [message]\n");
	if (!check_pid(argv[1]))
		print_err_client("\t./client_bonus <PID> [message]\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
