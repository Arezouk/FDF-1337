/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:22:45 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/17 22:29:21 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	purple(int *a, int *b)
{
	if (*a <= 1 && *a >= -1)
		*b = 0xE6E6FA;
	else if (*a <= 2 && *a >= -2)
		*b = 0xD8BFD8;
	else if (*a <= 3 && *a >= -3)
		*b = 0xDDA0DD;
	else if (*a <= 4 && *a >= -4)
		*b = 0xEE82EE;
	else if (*a <= 6 && *a >= -6)
		*b = 0xDA70D6;
	else if (*a <= 8 && *a >= -8)
		*b = 0xFF00FF;
	else if (*a <= 10 && *a >= -10)
		*b = 0xBA55D3;
	else if (*a <= 12 && *a >= -12)
		*b = 0x9370DB;
	else if (*a <= 13 && *a >= -13)
		*b = 0x8A2BE2;
	else if (*a <= 15 && *a >= -15)
		*b = 0x9400D3;
	else if (*a <= 17 && *a >= -17)
		*b = 0x9932CC;
	else if (*a >= 18 && *a <= -18)
		*b = 0x8B008B;
}

static void	rot(t_mlx *mlx, int i)
{
	purple(&(mlx->line->points[i]->value), &(mlx->hcolor));
	if (mlx->line->points[i + 1])
		draw_line(mlx, mlx->line->points[i],
				mlx->line->points[i + 1], mlx->hcolor);
	if (mlx->line->next)
		draw_line(mlx, mlx->line->points[i],
				mlx->line->next->points[i], mlx->hcolor);
	mlx->hcolor = 0xE6E6FA;
}

static void	rot2(t_mlx *mlx, int i)
{
	mlx->hcolor = 0xE6E6FA;
	if (mlx->line->points[i + 1])
		draw_line(mlx, mlx->line->points[i],
				mlx->line->points[i + 1], mlx->hcolor);
	if (mlx->line->next)
		draw_line(mlx, mlx->line->points[i],
				mlx->line->next->points[i], mlx->hcolor);
}

void		rotate_iso(t_mlx *mlx)
{
	int		i;
	t_line	*holder;

	mlx->line = create_coordinates(mlx->line, mlx->zoom);
	window_initialize(mlx);
	rotate(mlx);
	isometric(mlx);
	holder = mlx->line;
	while (mlx->line)
	{
		i = -1;
		while (mlx->line->points[++i])
			(mlx->line->points[i]->value != 0) ?
				rot(&(*mlx), i) : rot2(&(*mlx), i);
		mlx->line = mlx->line->next;
	}
	mlx->line = holder;
}

void		rotate_para(t_mlx *mlx)
{
	int		i;
	t_line	*holder;

	mlx->line = create_coordinates(mlx->line, mlx->zoom);
	window_initialize(mlx);
	rotate(mlx);
	holder = mlx->line;
	while (mlx->line)
	{
		i = -1;
		while (mlx->line->points[++i])
			(mlx->line->points[i]->value != 0) ?
				rot(&(*mlx), i) : rot2(&(*mlx), i);
		mlx->line = mlx->line->next;
	}
	mlx->line = holder;
}
