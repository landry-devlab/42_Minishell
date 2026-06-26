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

# ifndef MALLOC_ERROR
#  define MALLOC_ERROR 100
# endif
# ifndef READLINE_ERROR
#  define READLINE_ERROR 101
# endif
# ifndef FORK_ERROR
#  define FORK_ERROR 102
# endif
# ifndef WAITPID_ERROR
#  define WAITPID_ERROR 103
# endif
# ifndef ERROR
#  define ERROR 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif

typedef struct	s_minishell						//it will be our global variable
{
	//char			*environment;
  char          *line;  //the initial prompt
	struct s_cmd	*cmd;
	int				    exit_code;
}				t_minishell;

typedef struct	s_cmd
{
	int				id;
	char			**argv;
	struct s_cmd	*next;
}				t_cmd;


void  exit_after_error(int error, t_minishell gdata);
int		run_terminal(void);
void  parse_line(t_minishell	g_data);
void	execute_prompt(t_minishell g_data);
void	free_data(t_minishell	g_data);

void  ft_exit(t_minishell g_data);
void  ft_pwd(void);

#endif
