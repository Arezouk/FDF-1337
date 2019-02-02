/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:29:41 by arezouk           #+#    #+#             */
/*   Updated: 2018/12/23 06:03:46 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static int			ft_checkwords(char const *str, char c)
{
	int				i;
	int				words;

	i = 0;
	words = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static void			ft_alloc(char **tab, char const *str, char c)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	if (str == 0)
		return ;
	while (str[k] != '\0')
	{
		j = 1;
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k] != '\0')
		{
			k++;
			j++;
		}
		if (j != 1)
			tab[i++] = (char *)malloc(sizeof(char) * j);
	}
}

static void			ft_fill(char **tab, char const *str, int n, char c)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	if (str == 0)
		return ;
	while (i < n)
	{
		j = 0;
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k] != '\0')
		{
			tab[i][j] = str[k++];
			j++;
		}
		if (j > 0)
		{
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = 0;
}

char				**ft_strsplit(char *s, char c)
{
	int				words_c;
	char			**str;

	words_c = ft_checkwords(s, c);
	str = (char **)malloc(sizeof(*str) * (words_c + 1));
	if (s == 0)
		return (NULL);
	if (str == NULL)
		return (NULL);
	if (str)
	{
		ft_alloc(str, s, c);
		ft_fill(str, s, words_c, c);
		return (str);
	}
	return (0);
}
