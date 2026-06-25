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


#include "include/minishell.h"

void initialize_gdata(t_minishell	*g_data)
{
	g_data->cmd = malloc(sizeof(t_cmd));
	if (!g_data->cmd)
	  exit_after_error(MALLOC_ERROR, *g_data);
	g_data->cmd->next = NULL;
	g_data->cmd->argv = NULL;
	g_data->exit_code = 0;
}

int	run_terminal(void)
{
  t_minishell	g_data;

  initialize_gdata(&g_data);
	while (1)
	{
		g_data.line = readline("$: ");
		if (!g_data.line)
			exit_after_error(READLINE_ERROR, g_data);
		parse_line(g_data);
		execute_prompt(g_data);
	}
}
