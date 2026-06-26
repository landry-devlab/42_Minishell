/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:08:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/06/26 18:08:00 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void  ft_echo(char **argv)
{
  int newline;
  int i;
  int printed;

  newline = 1;
  i = 1;
  printed = 0;
  if (argv[1] && ft_strcmp(argv[1], "-n") == 0)
  {
    newline = 0;
    i = 2;
  }
  while (argv[i])
  {
    if (printed)
      printf(" ");
    printf("%s", argv[i++]);
    printed = 1;
  }
  if (newline)
    printf("\n");
}
