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

t_list	*new_t_list(t_list **list);
void	print_response(t_list *list);
void	free_list(t_list **node);
void	print_error_arg(void);
int     check_pid(char *argv);

#endif