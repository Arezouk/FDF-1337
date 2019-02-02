/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:36:21 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/12 14:12:35 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*ch;
	size_t	i;

	ch = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (ch != NULL)
	{
		while (i < size)
		{
			ch[i] = 0;
			i++;
		}
		ch[i] = '\0';
		return (ch);
	}
	return (0);
}
