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
# ifndef EXIT_ERROR
#  define EXIT_ERROR 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

typedef struct		s_cmd							//this is splited command linked list
{
	int				id;
	char			*initialcmd;
	char			**argv;
	struct s_cmd	*next;
}					t_cmd; 


typedef struct	s_minishell						//this is our main structure variable
{
	//char			*environment;
	char			*line;							//refers to the initial prompt
	t_cmd			*cmd_list;					//points to segments of the original prompt.
	int				exit_code;						//refers to an exit code
}				t_minishell;


int		run_terminal(void);
void	parse_line(t_minishell *s_data);
void	execute_prompt(t_minishell *s_data);

//cleanup
void	free_data(t_minishell *s_data);
void	free_cmd(t_cmd *cmd_list);
void	exit_after_error(int error_msg, t_minishell *s_data);

void	ft_exit(t_minishell *s_data);
void	ft_pwd(t_minishell *s_data);
void	ft_cd(char **argv, t_minishell *s_data);
void	ft_echo(char **argv, t_minishell *s_data);

#endif
