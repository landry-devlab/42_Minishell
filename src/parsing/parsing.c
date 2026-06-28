/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:00:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/25 14:32:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static int	generate_cmd(t_minishell *s_data)
{
	// to do : cut the prompt with |
	
	s_data->cmd_list = malloc(sizeof(t_cmd)); // just to verifi
	if (!s_data->cmd_list)
		return(printf("pb malloc dans la function de generate_cmd"), 1);
	s_data->cmd_list->initialcmd = ft_strdup(s_data->line);
	if (!s_data->cmd_list->initialcmd)
	{
		free (s_data->cmd_list);
		return(printf("pb malloc dans la function de generate_cmd"), 1);
	}
	s_data->cmd_list->next = NULL;
	s_data->cmd_list->argv = NULL;
	s_data->cmd_list->id = 0;

	return (0);
}


static int tokenize_cmd(t_minishell *s_data) // to ameliorate
{
	t_cmd	*tmp;

	tmp = s_data->cmd_list;
	while (tmp)
	{
		tmp->argv = ft_split(tmp->initialcmd, ' ');
		if (!tmp->argv)
		{
			perror("split");
			free_data(s_data);
			exit(1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	parse_line(t_minishell *s_data)
{
	if (generate_cmd(s_data)!= 0)
		s_data->exit_code = 2;   ///what is for?

	if (tokenize_cmd(s_data) !=0)
		s_data->exit_code = 2;   ///what is for?

}
