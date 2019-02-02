/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_one_o_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 04:24:11 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/17 22:29:35 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	blue(t_mlx *mlx, int i)
{
	int		j;

	j = mlx->line->points[i]->value;
	if (j <= 1 && mlx->line->points[i]->value >= -1)
		mlx->hcolor = 0xADD8E6;
	else if (j <= 2 && mlx->line->points[i]->value >= -2)
		mlx->hcolor = 0x87CEFA;
	else if (j <= 3 && mlx->line->points[i]->value >= -3)
		mlx->hcolor = 0x87CEEB;
	else if (j <= 4 && mlx->line->points[i]->value >= -4)
		mlx->hcolor = 0x00BFFF;
	else if (j <= 6 && mlx->line->points[i]->value >= -6)
		mlx->hcolor = 0x1E90FF;
	else if (j <= 8 && mlx->line->points[i]->value >= -8)
		mlx->hcolor = 0x4169E1;
	else if (j <= 10 && mlx->line->points[i]->value >= -10)
		mlx->hcolor = 0x0000FF;
	else if (j <= 12 && mlx->line->points[i]->value >= -12)
		mlx->hcolor = 0x0000CD;
	else if (j <= 13 && mlx->line->points[i]->value >= -13)
		mlx->hcolor = 0x00008B;
	else if (j <= 15 && mlx->line->points[i]->value >= -15)
		mlx->hcolor = 0x000080;
	else if (j >= 17 && mlx->line->points[i]->value <= -17)
		mlx->hcolor = 0x191970;
}

static void	rot(t_mlx *mlx, int i)
{
	blue(mlx, i);
	if (mlx->line->points[i + 1])
		draw_line(mlx, mlx->line->points[i],
				mlx->line->points[i + 1], mlx->hcolor);
	if (mlx->line->next)
		draw_line(mlx, mlx->line->points[i],
				mlx->line->next->points[i], mlx->hcolor);
	mlx->hcolor = 0xADD8E6;
}

static void	rot2(t_mlx *mlx, int i)
{
	mlx->hcolor = 0xADD8E6;
	if (mlx->line->points[i + 1])
		draw_line(mlx, mlx->line->points[i],
				mlx->line->points[i + 1], mlx->hcolor);
	if (mlx->line->next)
		draw_line(mlx, mlx->line->points[i],
				mlx->line->next->points[i], mlx->hcolor);
}

void		rotate_iso_b(t_mlx *mlx)
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

void		rotate_para_b(t_mlx *mlx)
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
