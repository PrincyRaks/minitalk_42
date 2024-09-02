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

static t_response	*get_lstlast(t_response *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static void	add_back(t_response **list, t_response *new)
{
	t_response	*end;

	if (list)
	{
		if (!*list)
			*list = new;
		else
		{
			end = get_lstlast(*list);
			if (end)
				end->next = new;
		}
	}
}

t_response	*new_t_response(t_response **list)
{
	t_response  *new;

	if (!list)
		return (NULL);
	new = (t_response *)malloc(sizeof(t_response));
	if (!new)
		return (NULL);
    new->n_used = 0;
	new->next = NULL;
	add_back(list, new);
	return (new);
}

static char	*strcpy_lst(char *dst, t_response *src, int len)
{
	int	i;
	int	j;

	if (!src)
		return (NULL);
	i = 0;
	while (src)
	{
		j = 0;		
		while (src->message[j] && (j < 500 && i < len))
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

char	*add_lstresponse(t_response *list)
{
	char		*message;
	int			len;
	t_response	*next_node;

	len = 0;
	next_node = list;
	while (next_node)
	{
		len += next_node->n_used;
		next_node = next_node->next;
	}
	message = (char*)malloc(sizeof(char) * (len + 1));
	if (!message)
		return (NULL);
	message = strcpy_lst(message, list, len);
	return (message);
}

void	free_list(t_response **node)
{
	t_response	*current;
	t_response	*next_node;

	current = *node;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

// char	*strjoin_data(char *s1, char c)
// {
// 	char	*new_s;
// 	char	*tmp_s1;
// 	int		len;

// 	if (s1 == NULL)
// 		s1 = ft_calloc(1, 1);
// 	len = ft_strlen(s1) + 1;
// 	new_s = ft_calloc(1, (len + 1));
// 	if (!new_s)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	tmp_s1 = s1;
// 	while (*tmp_s1)
// 		*(new_s++) = *(tmp_s1++);
// 	if (c)
// 		*(new_s++) = c;
// 	free(s1);
// 	return (new_s - len);
// }
