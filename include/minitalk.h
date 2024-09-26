/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:38:23 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/26 15:28:37 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
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
void				print_response(t_util **util, int pid);
void				free_list(t_util **lst);
void				print_err_client(void);
int					check_pid(char *argv);
void				print_error_sig(void);
void	print_err_client(void);
void	print_err_server(void);

#endif