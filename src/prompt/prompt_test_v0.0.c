/* it is just the function for the very first test*/

#include "include/minishell.h"

void ft_free_prompt(char **prompt, char *line)
{
	int i;

	if (line)
		free(line);

	i = 0;
	while (prompt[i])
	{
		free(prompt[i]);
		i++;
	}
	free(prompt);
}

int generate_prompt(char ***prompt, char *line)
{
	*prompt = ft_split(line, ' ');
	if (!*prompt)
		return(printf("Error : ft_split\n"),1);
	else
		return(0);
}
