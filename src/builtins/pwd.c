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

void  ft_pwd(void)
{
  static char  buf[4096];

  if (getcwd(buf, sizeof(buf)))
    printf("%s\n", buf);
}
