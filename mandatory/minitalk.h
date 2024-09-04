/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:38:23 by rrakotos          #+#    #+#             */
/*   Updated: 2024/08/30 11:23:28 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	char			message[500];
	int				n_used;
	struct s_node   *next;
}						t_node;
typedef	struct s_util
{
	t_node	*head;
	t_node	*tail;
} t_util;
void	new_t_node(t_util	**util);
void	print_response(t_util **util, int pid);
void	free_list(t_util **lst);
void	print_error_arg(void);
int     check_pid(char *argv);

#endif