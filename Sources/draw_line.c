/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:36:02 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/05 21:26:07 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	racc(t_mlx *mlx, int i, int color)
{
	mlx->error = mlx->dx / 2;
	while (i < mlx->dx)
	{
		mlx->x += mlx->xi;
		mlx->error += mlx->dy;
		if (mlx->error > mlx->dx)
		{
			mlx->error -= mlx->dx;
			mlx->y += mlx->yi;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, mlx->x, mlx->y, color);
		i++;
	}
}

void		draw_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2, int color)
{
	int	i;

	i = 0;
	ft_remp(&(*mlx), &(*coord1), &(*coord2));
	if (mlx->dx > mlx->dy)
		racc(&(*mlx), i, color);
	else
	{
		mlx->error = mlx->dy / 2;
		while (i < mlx->dy)
		{
			mlx->y += mlx->yi;
			mlx->error += mlx->dx;
			if (mlx->error > mlx->dy)
			{
				mlx->error -= mlx->dy;
				mlx->x += mlx->xi;
			}
			mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, mlx->x, mlx->y, color);
			i++;
		}
	}
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, coord2->x + mlx->left_right
			, coord2->y + mlx->up_down, color);
}
