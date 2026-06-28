/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:32:39 by llarrive          #+#    #+#             */
/*   Updated: 2026/06/01 14:32:43 by llarrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is our main function which lauch our minishell. */

#include "include/minishell.h"

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;

	if (argc > 1)
		return(printf("Error : arguments \n"), 1);

	return(run_terminal());
}
