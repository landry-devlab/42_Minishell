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

static void ft_free_prompt(char **prompt, char *line)
{
	int i;

	if (line)
		free(line);

	i = 0;
	while (prompt[i])
	{
		free(prompt[i]);
		i++;
	}
	free(prompt);
}

void free_data(t_minishell g_data)
{
  ft_free_prompt(g_data.cmd->argv, g_data.line);
}
