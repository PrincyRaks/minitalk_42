/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:47:25 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/26 15:13:05 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	append_back(t_util **util, t_node *node)
{
	if ((*util)->head == NULL)
	{
		(*util)->head = node;
		(*util)->tail = node;
	}
	else
	{
		(*util)->tail->next = node;
		(*util)->tail = node;
	}
}

void	new_t_node(t_util **util)
{
	t_node	*node;

	if (!util)
		return ;
	if (!*util)
	{
		*util = (t_util *)malloc(sizeof(t_util));
		if (!*util)
			return ;
		(*util)->head = NULL;
		(*util)->tail = NULL;
	}
	node = malloc(sizeof(t_node));
	if (!node)
	{
		free_list(util);
		return ;
	}
	node->n_used = 0;
	node->next = NULL;
	ft_bzero(node->message, 500);
	append_back(util, node);
}

static char	*strcpy_lst(char *dst, t_node *src)
{
	int	i;
	int	j;

	if (!src)
		return (NULL);
	i = 0;
	while (src)
	{
		j = 0;
		while (src->message[j] && j < 500)
		{
			dst[i] = src->message[j];
			i++;
			j++;
		}
		src = src->next;
	}
	dst[i] = '\0';
	return (dst);
}

void	print_response(t_util **util, int pid)
{
	char	*message;
	int		len;
	t_node	*next_node;

	len = 0;
	next_node = (*util)->head;
	while (next_node)
	{
		len += next_node->n_used;
		next_node = next_node->next;
	}
	message = (char *)malloc(sizeof(char) * (len + 1));
	if (!message)
	{
		free_list(util);
		exit(1);
	}
	message = strcpy_lst(message, (*util)->head);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	free(message);
	free_list(util);
	if (kill(pid, SIGUSR2))
		print_error("Error sending signal to client\n");
}
