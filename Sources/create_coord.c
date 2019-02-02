/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 04:44:50 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/07 04:50:33 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*create_coordinates(t_line *line, int zoom)
{
	int		i;
	int		z;
	t_line	*holder;

	holder = line;
	z = zoom;
	while (line)
	{
		i = -1;
		while (line->points[++i])
			if (i == 0)
			{
				line->points[i]->x = zoom;
				line->points[i]->y = z;
			}
			else
			{
				line->points[i]->x = line->points[i - 1]->x + zoom;
				line->points[i]->y = line->points[i - 1]->y;
			}
		z += zoom;
		line = line->next;
	}
	return (holder);
}
