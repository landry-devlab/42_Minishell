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

//function when starting the program
int		run_terminal(void);


//function from the prompt files - when very first test
void	ft_free_prompt(char **prompt, char *line);
int		generate_prompt(char ***prompt, char *line);


//function for execution
int		execute_prompt(char **prompt);



//functions from libft - just for testing - has to be remove when libft put in the file
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);







#endif
