/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:32:17 by gcelesti          #+#    #+#             */
/*   Updated: 2026/05/26 13:32:17 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	dest_len;

	dest_len = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0' && (dest_len + i + 1) < len)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (dest_len < len)
		dst[dest_len + i] = '\0';
	return (dst);
}