/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:47:25 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/02 15:05:55 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	free_list(t_list **node)
{
	t_list	*current;
	t_list	*next_node;

	current = *node;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

t_list	*new_t_list(t_list **list)
{
	t_list  *new;

	if (!list)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free_list(&(*list)->head);
		return (NULL);
	}
    new->n_used = 0;
	new->next = NULL;
	ft_lstadd_back(list, new);
	return (new);
}

static char	*strcpy_lst(char *dst, t_list *src)
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

void	print_response(t_list *list)
{
	char		*message;
	int			len;
	t_list	*next_node;

	len = 0;
	next_node = list->head;
	while (next_node)
	{
		len += next_node->n_used;
		next_node = next_node->next;
	}
	message = (char*)malloc(sizeof(char) * (len + 1));
	if (!message)
	{
		free_list(&list->head);
		exit(1);
	}
	message = strcpy_lst(message, list->head);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	free(message);
}
