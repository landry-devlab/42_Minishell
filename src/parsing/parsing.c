/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:00:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/25 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int generate_prompt(char ***prompt, char *line)
{
	*prompt = ft_split(line, ' ');
	if (!*prompt)
		return(1);
	else
		return(0);
}

void parse_line(t_minishell	g_data)
{
  if (generate_prompt(&g_data.cmd->argv, g_data.line) != 0)
				g_data.exit_code = 2;
}
