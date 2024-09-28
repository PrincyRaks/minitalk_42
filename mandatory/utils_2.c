/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:13:42 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 14:50:45 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_err_client(char *str)
{
	ft_putstr_fd("\033[91mERROR: Wrong format! insert this way:\n\033[0m", 2);
	ft_putstr_fd("\033[91mPID : should be integer and positive \n\033[0m", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	print_err_server(char *str)
{
	ft_putstr_fd("\033[91mERROR: Wrong format! insert this way:\n\033[0m", 2);
	ft_putstr_fd(str, 2);
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

void	print_error(char *str)
{
	ft_putstr_fd("❌ ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	free_list(t_util **lst)
{
	t_node	*current;
	t_node	*next_node;

	current = (*lst)->head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(*lst);
	*lst = NULL;
}
