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

t_minishell	g_data;									// our global variable is declared here

int	error_message(void);

void initialize_gdata()
{
	g_data.cmd = malloc(sizeof(t_cmd));
	if (!g_data.cmd)
		g_data.exit_code = MALLOC_ERROR;
	else
	{
		g_data.cmd->next_cmd = NULL;
		g_data.cmd->cmd = NULL;
		g_data.cmd->exe_cmd = NULL;
		g_data.exit_code = 0;
	}
}

int	run_terminal(void)
{
	int return_code;

	if (!g_data.cmd)
		initialize_gdata();								//initialize the gobal variable - To do : isolate to a initialize function

	while (1)
	{
		g_data.line = readline("$: ");				//read the user prompt of our minishell
		if (!g_data.line)
			g_data.exit_code = 1;
		else if (g_data.line[0] == '\0')			//generate a new prompt line in case empty prompt(case enter pressed)
		{
			free(g_data.line);
			continue;
		}
		else
		{
			g_data.cmd->cmd = g_data.line; 	///to do: split the prompt un bloc of cmd regarding | < > << >>
			// We continue the programm with only one prompt bloc

			if (generate_prompt(&g_data.cmd->exe_cmd, g_data.cmd->cmd) != 0)
				g_data.exit_code = 2;

			g_data.exit_code = execute_prompt(g_data.cmd->exe_cmd);
			if (g_data.exit_code == 0)					//all good -> regenerate a line prompt in our minishell
				continue;
			else
				break;
		}
	}
	return_code = error_message();						//make our minishell print an error message and define a return code 
	ft_free_prompt(g_data.cmd->exe_cmd, g_data.cmd->cmd);
	return(return_code);
}

int	error_message(void)									//to do : ameliorate the error_message function
{
	if (g_data.exit_code == 0)
		return(0);
	else if (g_data.exit_code == 1)
		return(printf("Error : readline\n"), 1);
	else if (g_data.exit_code == 2)
		return(printf("Error : ft_split\n"),1);
	else if (g_data.exit_code == 3)
		return(printf("Exit minishell\n"),0);
	else if (g_data.exit_code == MALLOC_ERROR)
		return(printf("Error : malloc\n"),1);
	else
		return(printf("!!! other !!\n"),1);				//impliment here fallowing the situation
}