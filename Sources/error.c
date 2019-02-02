/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:47:53 by hessabra          #+#    #+#             */
/*   Updated: 2019/01/11 22:16:45 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

static void	racc(char *c)
{
	ft_putstr(c);
	write(1, "\n", 1);
	exit(1);
}

void		linerror(int j)
{
	static int	x = 0;

	if (x == 0)
		x = j;
	if (j != x)
	{
		ft_putstr("Found wrong line length. Exiting\n");
		exit(1);
	}
}

void		error(char *gv, int *ret, t_line *line)
{
	static int	x = 0;
	int			l;
	char		*c;

	c = NULL;
	if (x == 0)
	{
		l = ft_strlen(gv);
		if (gv[l - 1] != 'f' || gv[l - 2] != 'd'
				|| gv[l - 3] != 'f' || gv[l - 4] != '.')
			c = "Not a < .fdf > file";
		x++;
	}
	*ret = open(gv, O_RDONLY);
	if (*ret < 0 && x == 1)
		c = ft_strjoin("No file ", gv);
	if (line == NULL && x == 2)
		c = "No data found.";
	if (c != NULL)
		racc(c);
	x++;
}
