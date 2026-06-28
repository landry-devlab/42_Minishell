/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:00:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/26 15:11:00 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	ft_exit(t_minishell *s_data)
{
	free_data(s_data);
	write(2, "exit\n", 5);
	exit(s_data->exit_code);
}
