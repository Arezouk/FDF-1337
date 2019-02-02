/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:37:05 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/08 22:30:21 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ch;

	ch = (char *)s;
	len = 0;
	i = 0;
	while (ch[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
