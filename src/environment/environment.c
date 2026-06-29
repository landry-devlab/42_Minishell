/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:32:39 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/29 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/minishell.h"

t_env	*init_env(char **envp)
{
	t_env	*env;

	printf("DEBUG I will loop though envp and update the env. TBD, now do nothing\n");
	printf("%s\n", envp[0]);
	env = malloc(sizeof(t_env *));
	return (env);
}

void	print_env(t_minishell s_data)
{
	printf("DEBUG I will loop though s_data.envp print env. TBD, now do nothing\n");
	printf("DEBUG: env pointer: %p\n", s_data.env);
}
