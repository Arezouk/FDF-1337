/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:11:58 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/08 17:38:21 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi(const char *nptr)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	j = 0;
	while (nptr[j] == '\n' || nptr[j] == '\0' || nptr[j] == '\t'
			|| nptr[j] == '\r' || nptr[j] == '\f' || nptr[j] == '\v'
			|| nptr[j] == ' ')
		j++;
	if (nptr[j] == '-')
	{
		i = -1;
		j++;
	}
	else if (nptr[j] == '+')
		j++;
	while (nptr[j] != '\0' && nptr[j] >= '0' && nptr[j] <= '9')
	{
		n = n * 10 + (nptr[j] - '0');
		j++;
	}
	return (n * i);
}
