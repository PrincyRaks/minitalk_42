/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:13:42 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:12:47 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_err_client(char *str)
{
	ft_printf("\033[91mERROR: Wrong format! insert this way:\n\033[0m");
	ft_printf("\033[91mPID : should be integer and positive \n%s\033[0m", str);
	exit(1);
}

void	print_err_server(char *str)
{
	ft_printf("\033[91mERROR: Wrong format! insert this way:\n%s\033[0m", str);
	exit(1);
}

int	check_pid(char *argv)
{
	while (*argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (0);
		argv++;
	}
	return (1);
}

void	print_error(char *str)
{
	ft_printf("❌ %s", str);
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
