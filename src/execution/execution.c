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

int	ft_ext_call(char *const prompt[]);


int	execute_prompt(char **prompt)						//to do : develop this function and functionalities
{
	pid_t	pid;

	if (!prompt || !prompt[0])
		return(1);

	if (strcmp(prompt[0], "exit") == 0)					//manage 'exit' request
		return(3);

	else												//manage builin function
	{
		pid = fork();

		if (pid < 0)
			return(printf("error fork\n"), 1);
		
		if (pid == 0)
			return(execvp(prompt[0], prompt), 0);
	
		else
		{
			if (waitpid(pid, NULL, 0) == -1)
				return(printf("error waitpid\n"), 1);
		}
	}	
	
	return (0);
}
