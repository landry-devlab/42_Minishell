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

static int	is_builtin(char *command)
{
	if (
		ft_strcmp(command, "exit") == 0 ||
		ft_strcmp(command, "pwd") == 0 ||
		ft_strcmp(command, "cd") == 0 ||
		ft_strcmp(command, "echo") == 0
	)
		return (1);
	else
		return (0);
}

static void	execute_builtin(char **argv, t_minishell *s_data) // probleme with the return code 1 / 0
{
	// printf("DEBUG Executing builtin:%s\n", argv[0]);
	if (ft_strcmp(argv[0], "exit") == 0)
		ft_exit(s_data);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return(ft_pwd(s_data));
	else if (ft_strcmp(argv[0], "cd") == 0)
		return(ft_cd(argv, s_data));
	else if (ft_strcmp(argv[0], "echo") == 0)
		return(ft_echo(argv, s_data));

	printf("DEBUG Builtin:%s not found\n", argv[0]);
}

static char *get_pathname(char **argv)
{
	if (ft_strcmp(argv[0], "ls") == 0)					//manage 'exit' request
		return("/usr/bin/ls");
	else
		return("");
}

void	execute_external(char **argv, t_minishell *s_data)
{
	pid_t	pid;
	char *pathname;

	// printf("DEBUG Executing external:%s\n", argv[0]);
	pathname = get_pathname(argv);
	if (strcmp(pathname, "") == 0)
	{
		printf("Command not found:%s\n", argv[0]);
		return;
	}
	pid = fork();
	if (pid < 0)
		exit_after_error(FORK_ERROR, s_data);
	if (pid == 0)
		execve(pathname, argv, NULL);
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
			exit_after_error(WAITPID_ERROR, s_data);
	}
	// printf("DEBUG Finish executing external:%s\n", argv[0]);
}

static void	execute_command(char **argv, t_minishell *s_data)
{
	if (!argv || !argv[0])
		return;
	if (is_builtin(argv[0]))
		execute_builtin(argv, s_data);
	else
		execute_external(argv, s_data);
}

void	execute_prompt(t_minishell *s_data)
{
	execute_command(s_data->cmd_list->argv, s_data);
}
