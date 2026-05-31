/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:49:31 by gcelesti          #+#    #+#             */
/*   Updated: 2026/05/30 12:49:31 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;
	size_t s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';

	return (str);
}