/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:20:36 by gcelesti          #+#    #+#             */
/*   Updated: 2026/06/02 20:20:36 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **str, size_t i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
}

static int	next_word(const char *s, char c, size_t *i, char **out)
{
	size_t	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (*i > start)
	{
		*out = ft_substr(s, start, *i - start);
		if (!*out)
			return (0);
		return (1);
	}
	return (2);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	int		status;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		status = next_word(s, c, &i, &str[j]);
		if (status == 1)
			j++;
		else if (status == 0)
			return (free_split(str, j), NULL);
	}
	str[j] = NULL;
	return (str);
}
