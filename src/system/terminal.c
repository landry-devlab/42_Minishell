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

int	run_terminal(void)
{
	int return_code;

	if (!g_data.cmd)								//initialize the gobal variable
	{
		g_data.cmd = malloc(sizeof(t_cmd));
		if (!g_data.cmd)
			g_data.exit_code = 4;
		else
		{
			g_data.cmd->next_commande = NULL;
			g_data.cmd->commande = NULL;
			g_data.cmd->exe_commande = NULL;
			g_data.exit_code = 0;
		}
	}

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
			g_data.cmd->commande = g_data.line; 	///to do: split the prompt un bloc of commande regarding | < > << >>
			// We continue the programm with only one prompt bloc

			if (generate_prompt(&g_data.cmd->exe_commande, g_data.cmd->commande) != 0)
				g_data.exit_code = 2;

			g_data.exit_code = execute_prompt(g_data.cmd->exe_commande);
			if (g_data.exit_code == 0)					//all good -> regenerate a line prompt in our minishell
				continue;
			else
				break;
		}
	}
	return_code = error_message();
	ft_free_prompt(g_data.cmd->exe_commande, g_data.cmd->commande);
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
	else if (g_data.exit_code == 4)
		return(printf("Error : malloc\n"),1);
	else
		return(printf("!!! other !!\n"),1);				//impliment here fallowing the situation
}