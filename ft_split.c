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

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);

	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;

		start = i;

		while (s[i] && s[i] != c)
			i++;

		if (i > start)
		{
			str[j] = ft_substr(s, start, i - start);
			if (!str[j])
			{
				free_split(str, j);
				return (NULL);
			}
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}