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

static int	execute_builtin(char **argv, t_minishell g_data)
{
  printf("Executing builtin:%s\n", argv[0]);
  if (ft_strcmp(argv[0], "exit") == 0)
    ft_exit(g_data);
  else if (ft_strcmp(argv[0], "pwd") == 0)
    return(ft_pwd(), 1);

  printf("Builtin:%s not found\n", argv[0]);
  return (0);
}

static char *get_pathname(char **argv)
{
 	if (strcmp(argv[0], "ls") == 0)					//manage 'exit' request
		return("/usr/bin/ls");
  else
    return("");
}

void	execute_external(char **argv, t_minishell g_data)
{
	pid_t	pid;
	char *pathname;

	printf("Executing external:%s\n", argv[0]);
	pathname = get_pathname(argv);
	if (strcmp(pathname, "") == 0)
	{
	  printf("Command not found:%s\n", argv[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
	  exit_after_error(FORK_ERROR, g_data);
	if (pid == 0)
		execve(pathname, argv, NULL);
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		  exit_after_error(WAITPID_ERROR, g_data);
	}
}

static void	execute_command(char **argv, t_minishell g_data)
{
  if (!execute_builtin(argv, g_data))
    execute_external(argv, g_data);
}

void	execute_prompt(t_minishell g_data)
{
  execute_command(g_data.cmd->argv, g_data);
}
