/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:38:23 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/28 16:58:05 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libprintf/libftprintf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			message[500];
	int				n_used;
	struct s_node	*next;
}					t_node;
typedef struct s_util
{
	t_node			*head;
	t_node			*tail;
}					t_util;
void				new_t_node(t_util **util);
void				free_list(t_util **lst);
int					check_pid(char *argv);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *nptr);
void				print_error(char *str);
void				print_err_client(char *str);
void				print_err_server(char *str);
void				print_response(t_util **util, int pid);
void				process_message(t_util **util, int pid);

#endif