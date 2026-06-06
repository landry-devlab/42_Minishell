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

int main()
{
	pid_t pid;
	char **prompt;
	char *line;

	while (1)
	{
		line = readline("$: ");
		if (line == NULL)
			exit(1);

		prompt = ft_prompt(line);
		free(line);

		if (strcmp(prompt[0], "exit") == 0)
		{
			ft_free_prompt(prompt);
			exit(0);
		}
		else if (strcmp(prompt[0], "echo") == 0)
		{
			printf("echo\n");
		}

		//else if (strcmp(prompt[0], "ls") == 0)
		else
		{
			pid = fork();

			if (pid < 0)
			{
				ft_free_prompt(prompt);
				return(printf("error fork\n"), 1);
			}
			
			if (pid == 0)
				ft_ext_call(prompt);

			
			else
			{
				if (waitpid(pid, NULL, 0) == -1)
					return(printf("error waitpid\n"), 1);
			}
		}	
		
	ft_free_prompt(prompt);
	}

	return(0);
}