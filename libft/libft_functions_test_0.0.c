/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_test0.0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llarrive <llarrive@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:32:39 by llarrive          #+#    #+#             */
/*   Updated: 2026/06/01 14:32:43 by llarrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
it is just the libft functions for the very first test
will be replace by the libtf folder

*/

#include "include/minishell.h"

//for ft_split
static int	ft_count_part(char const *str, char c);
static void	ft_initiate_variable(int *i, int *pos);
static void	ft_initiate_variable(int *i, int *pos);
static void	*ft_free_array(char **array, int i);


char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		pos;

	if (!s || !*s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_part(s, c) + 1));
	if (!split)
		return (NULL);
	ft_initiate_variable(&i, &pos);
	while (i < ft_count_part(s, c))
	{
		while (s[pos] && s[pos] == c)
			pos++;
		j = 0;
		while (s[pos + j] != '\0' && s[pos + j] != c)
			j++;
		split[i] = ft_substr(s, pos, j);
		if (!split[i])
			return (ft_free_array(split, i));
		pos = pos + j;
		i++;
	}
	split[i] = NULL;
	return (split);
}

static int	ft_count_part(char const *str, char c)
{
	size_t	i;
	size_t	nb_part;

	i = 0;
	nb_part = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else if (str[i] != c)
		{
			nb_part++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (nb_part);
}

static void	ft_initiate_variable(int *i, int *pos)
{
	*i = 0;
	*pos = 0;
}

static void	*ft_free_array(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return (NULL);
}



char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	lstr;

	if (!str)
		return (NULL);
	lstr = ft_strlen(str);
	if (start > lstr)
		return (ft_calloc(1, 1));
	if (len + start > lstr)
		len = lstr - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((SIZE_MAX / nmemb) < size)
		return (NULL);
	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
