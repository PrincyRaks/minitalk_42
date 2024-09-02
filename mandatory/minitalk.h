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
# include <unistd.h>

typedef struct s_response
{
	char				message[500];
	int					n_used;
	struct s_response	*next;
}						t_response;
// char	*strjoin_data(char *s1, char c);
t_response	*new_t_response(t_response **list);
char	*add_lstresponse(t_response *list);
void	free_list(t_response **node);
void	print_error_arg(void);
int     check_pid(char *argv);


#endif