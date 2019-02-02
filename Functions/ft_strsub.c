/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:50:15 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/16 01:38:22 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	tab = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (s == 0 || *s == 0)
		return (0);
	if (tab)
	{
		s = s + start;
		while (i < len)
		{
			tab[i] = s[i];
			i++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
