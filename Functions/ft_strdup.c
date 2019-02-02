/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:29:46 by arezouk           #+#    #+#             */
/*   Updated: 2018/10/15 18:36:56 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*ch;
	char	*ch1;
	char	*ch2;
	int		i;

	i = 1;
	ch2 = (char *)s1;
	while (*ch2++ != '\0')
		i++;
	ch = (char *)malloc(sizeof(char) * i);
	ch1 = ch;
	if (ch == NULL)
		return (NULL);
	else
		while (*s1 != '\0')
		{
			*ch = *s1;
			ch++;
			s1++;
		}
	*ch = '\0';
	return (ch1);
}
