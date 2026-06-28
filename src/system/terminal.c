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

static void initialize_sdata(t_minishell *s_data)
{
	s_data->line = NULL;
	s_data->cmd_list = NULL;
	s_data->exit_code = 0;
}

int	run_terminal(void)
{
	t_minishell	s_data;

	initialize_sdata(&s_data);
	while (1)
	{
		s_data.line = readline("$: ");
		if (!s_data.line)
			exit_after_error(READLINE_ERROR, &s_data);
		parse_line(&s_data);
		execute_prompt(&s_data);
		free_data(&s_data);
	}
}
