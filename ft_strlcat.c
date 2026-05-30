/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:32:17 by gcelesti          #+#    #+#             */
/*   Updated: 2026/05/29 09:09:47 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i + 1) < size)
	{
		dst[dest_len + 1] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (i + dest_len);
}
