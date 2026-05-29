/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:12:08 by gcelesti          #+#    #+#             */
/*   Updated: 2026/05/28 21:12:08 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_strdup(const char *s)
{
	void	*ptr;
	size_t	i;

	i = ft_strlen(s);
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, i);

	return (ptr);
}