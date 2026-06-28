/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:00:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/25 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	This is our clean and free function.
 	free_cmd clean the different command
	free_data clean and reset to NULL the data structure
	exit_after_error function print to stderr information in case of problems
	*/
#include "include/minishell.h"

void free_cmd(t_cmd *cmd_list)
{
	int 	i;
	t_cmd	*next;

	while (cmd_list)
	{
		next = cmd_list->next;
		free(cmd_list->initialcmd);
		if (cmd_list->argv)
		{
			i = 0;
			while (cmd_list->argv[i])
			{
				free(cmd_list->argv[i]);
				i++;
			}
			free(cmd_list->argv);
		}
		free(cmd_list);
		cmd_list = next;
	}
}

void free_data(t_minishell *s_data)
{
	if (s_data->line)
		free(s_data->line);
	s_data->line = NULL;
	if (s_data->cmd_list)
		free_cmd(s_data->cmd_list);
	s_data->cmd_list = NULL;
}

void	exit_after_error(int error_msg, t_minishell *s_data)
{
	if (error_msg == MALLOC_ERROR)
		perror("malloc");
	if (error_msg == READLINE_ERROR)
		perror("readline");
	free_data(s_data);
	exit(1);
}
