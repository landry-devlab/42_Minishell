/* it is just the function for the very first test*/

#include "include/minishell.h"

void ft_free_prompt(char **prompt)
{
	int i;

	i = 0;
	while (prompt[i])
	{
		free(prompt[i]);
		i++;
	}
	free(prompt);
}

char **ft_prompt(char *line)
{
	char **prompt;

	prompt = ft_split(line, ' ');
	return (prompt);
}


void ft_ext_call(char *const prompt[])
{
	execvp(prompt[0], prompt);
}