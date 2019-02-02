/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:14:55 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/16 01:45:13 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static	int			ft_slen(char const *s)
{
	int				i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char			*ft_concat(char *str, char const *s1, char const *s2)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	while (s1[j])
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size;
	char			*str;
	int				i;
	int				j;

	size = sizeof(*str) * (ft_slen(s1) + ft_slen(s2)) + 1;
	str = (char *)malloc(size);
	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (str)
	{
		str = ft_concat(str, s1, s2);
		return (str);
	}
	return (0);
}
