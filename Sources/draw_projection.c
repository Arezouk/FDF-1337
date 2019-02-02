/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 04:35:32 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/07 04:52:20 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(t_mlx *mlx)
{
	int		i;
	t_line	*tmp;

	tmp = mlx->line;
	while (mlx->line)
	{
		i = 0;
		while (mlx->line->points[i])
		{
			mlx->holder = 0;
			if (mlx->line->points[i]->value != 0)
				mlx->holder = (mlx->line->points[i]->value * mlx->height);
			isometric_rotation(&(mlx->line->points[i]->x),
			&(mlx->line->points[i]->y),
				mlx->line->points[i]->value + mlx->holder);
			i++;
		}
		mlx->line = mlx->line->next;
	}
	mlx->line = tmp;
}

void		rotate(t_mlx *mlx)
{
	int		i;
	t_line	*holder;

	holder = mlx->line;
	while (mlx->line)
	{
		i = 0;
		while (mlx->line->points[i])
		{
			le_rotation(&(mlx->line->points[i]->x), &(mlx->line->points[i]->y)
					, mlx->rotation);
			i++;
		}
		mlx->line = mlx->line->next;
	}
	mlx->line = holder;
}
