/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:15:26 by gcelesti          #+#    #+#             */
/*   Updated: 2026/06/05 10:08:22 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	sum;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	sum = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n')
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign *= -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * sum);
}
