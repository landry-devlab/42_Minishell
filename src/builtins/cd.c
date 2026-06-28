/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:36:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/26 15:36:00 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void  ft_cd(char **argv, t_minishell *s_data)
{
  if (argv[1])
  {
    s_data->exit_code = chdir(argv[1]);
    if (s_data->exit_code)
      perror("cd");
  }
  else
    write(2, "Switching to the HOME folder is not implemented\n", 48);
}
