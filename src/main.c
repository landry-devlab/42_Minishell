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

//t_minishell	g_data;

//int	init_minishell(t_minishell g_data);

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;

	if (argc > 1)
		return(printf("Error : argument number \n"), 1);
	
	//to do... an exit code system
/*
	if (init_minishell(g_data) !=0)
		return (1);
*/
	return(run_terminal());
}
/*
int	init_minishell(t_minishell g_data)
{
	if (!g_data.cmd)
	{
		g_data.cmd = malloc(sizeof(t_cmd));
		if (!g_data.cmd)
			return (1);
		g_data.cmd->next_commande = NULL;
		g_data.cmd->commande = NULL;
		g_data.cmd->exe_commande = NULL;
	}
	return(0);
}*/
