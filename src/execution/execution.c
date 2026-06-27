/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:32:39 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/24 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/minishell.h"

static int	execute_builtin(char **argv, t_minishell *g_data)
{
  printf("DEBUG Executing builtin:%s\n", argv[0]);
  if (ft_strcmp(argv[0], "exit") == 0)
    ft_exit(g_data);
  else if (ft_strcmp(argv[0], "pwd") == 0)
    return(ft_pwd(g_data), 1);
  else if (ft_strcmp(argv[0], "cd") == 0)
    return(ft_cd(argv, g_data), 1);
  else if (ft_strcmp(argv[0], "echo") == 0)
    return(ft_echo(argv, g_data), 1);

  printf("DEBUG Builtin:%s not found\n", argv[0]);
  return (0);
}

static char *get_pathname(char **argv)
{
 	if (strcmp(argv[0], "ls") == 0)					//manage 'exit' request
		return("/usr/bin/ls");
  else
    return("");
}

void	execute_external(char **argv, t_minishell *g_data)
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
	  exit_after_error(FORK_ERROR, *g_data);
	if (pid == 0)
		execve(pathname, argv, NULL);
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		  exit_after_error(WAITPID_ERROR, *g_data);
	}
}

static void	execute_command(char **argv, t_minishell *g_data)
{
	if (!argv || !argv[0])
		return;	
	if (!execute_builtin(argv, g_data))
    execute_external(argv, g_data);
}

void	execute_prompt(t_minishell *g_data)
{
  execute_command(g_data->cmd->argv, g_data);
}
