/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:32:39 by llarrive          #+#    #+#             */
/*   Updated: 2026/06/01 14:32:43 by llarrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/minishell.h"


int	run_terminal(void)
{
	char	*line;
	char	**prompt;
	int		status;

	while (1)
	{
		line = readline("$: ");
		if (!line)
			return(printf("Error : readline\n"), 1);
		else if (line[0] == '\0')//generate a new commande line in case of nothing in minishell prompt
		{
			free(line);
			continue;
		}
		else
		{
			prompt = NULL;
			if (generate_prompt(&prompt, line) != 0)
			{
				free(line);
				return(1);
			}
			status = execute_prompt(prompt);
			if (status == 0)
			{
				ft_free_prompt(prompt, line);
				continue;
			}
			else if (status == 2)
			{
				ft_free_prompt(prompt, line);
				return(0);
			}
			else
			{
				ft_free_prompt(prompt, line);
				return(1);
			}
		}
	}
	return(0);
}
