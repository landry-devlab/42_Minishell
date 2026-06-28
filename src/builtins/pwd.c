/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:12:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/26 15:12:00 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void  ft_pwd(t_minishell *s_data)
{
  static char  buf[4096];

  if (getcwd(buf, sizeof(buf)))
    printf("%s\n", buf);
  s_data->exit_code = EXIT_SUCCESS;
}
