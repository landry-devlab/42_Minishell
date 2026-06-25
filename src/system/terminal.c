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

t_minishell	g_data;									// our global variable is declared here

void initialize_gdata()
{
	g_data.cmd = malloc(sizeof(t_cmd));
	if (!g_data.cmd)
		g_data.exit_code = MALLOC_ERROR;
	else
	{
		g_data.cmd->next = NULL;
		g_data.cmd->argv = NULL;
		g_data.exit_code = 0;
	}
}

int	print_error_message(void)									//to do : ameliorate the error_message function
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

int	run_terminal(void)
{
	int return_code;

	initialize_gdata();
	while (1)
	{
		g_data.line = readline("$: ");
		if (!g_data.line)
			g_data.exit_code = 1;
		else if (g_data.line[0] == '\0')
		{
			free(g_data.line);
			continue;
		}
		else
		{
			parse_line(g_data);
			g_data.exit_code = execute_prompt(g_data.cmd->argv);
			if (g_data.exit_code != 0)					//all good -> regenerate a line prompt in our minishell
				break;
		}
	}
	return_code = print_error_message();						//make our minishell print an error message and define a return code
	free_data(g_data);
	return(return_code);
}
