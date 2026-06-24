/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:32:39 by llarrive          #+#    #+#             */
/*   Updated: 2026/06/02 06:32:13 by llarrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"

// EXIT codes
# ifndef MALLOC_ERROR
#  define MALLOC_ERROR 4
# endif

typedef struct	s_minishell						//it will be our global variable
{
	//char			*environnement;
	char			*line;//the initial prompt
	struct s_cmd	*cmd;//pointer to list of prompted cmd;
	int				exit_code;
}				t_minishell;

typedef struct	s_cmd
{
	int				id;
	char			*cmd;//the piece of prompt corresponding to a cmd
	char			**exe_cmd;// the tab of token for execution
	struct s_cmd	*next_cmd;
}				t_cmd;


//function when starting the program
int		run_terminal(void);


//function from the prompt files - when very first test
void	ft_free_prompt(char **prompt, char *line);
int		generate_prompt(char ***prompt, char *line);


//function for execution
int		execute_prompt(char **prompt);




#endif
