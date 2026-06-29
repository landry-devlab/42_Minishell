/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:32:39 by llarrive          #+#    #+#             */
/*   Updated: 2026/06/25 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is our minishell terminal function. */


#include "include/minishell.h"

int	initialize_sdata(t_minishell *s_data, char **envp)
{
	s_data->line = NULL;
	s_data->cmd_list = NULL;
	s_data->env = NULL;
	s_data->exit_code = 0;
	s_data->env = init_env(envp);
	// TODO
	// if init_env returns NULL - handle the malloc error on initialization
	return (0);
}

int	run_terminal(t_minishell	*s_data)
{
	while (1)
	{
		s_data->line = readline("$: ");
		if (!s_data->line)
			exit_after_error(READLINE_ERROR, s_data);
		parse_line(s_data);
		execute_prompt(s_data);
		free_data(s_data);
	}
	return (s_data->exit_code);
}
