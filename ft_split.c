/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:20:36 by gcelesti          #+#    #+#             */
/*   Updated: 2026/06/11 00:00:00 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *pos)
{
	int		start;
	int		len;
	char	*word;

	while (s[*pos] && s[*pos] == c)
		(*pos)++;
	start = *pos;
	while (s[*pos] && s[*pos] != c)
		(*pos)++;
	len = *pos - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static void	*free_result(char **result, int size)
{
	while (size-- > 0)
		free(result[size]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < words)
	{
		result[i] = get_word(s, c, &pos);
		if (!result[i])
			return (free_result(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
