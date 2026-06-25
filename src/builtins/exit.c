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

void  ft_exit(char **argv, t_minishell g_data)
{
  if (argv[1])
  {
    printf("exit with arguments\n");
    exit(ft_atoi(argv[1]));
  }
  else
  {
    printf("exit without arguments\n");
    exit(g_data.exit_code);
  }
}
