/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:35:39 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/07 17:26:08 by hessabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_n_project(t_mlx *mlx)
{
	if (mlx->pcolor == 0)
	{
		if (mlx->projection == 0)
			rotate_iso(mlx);
		else if (mlx->projection == -1)
			rotate_para(mlx);
	}
	else if (mlx->pcolor == -1)
	{
		if (mlx->projection == 0)
			rotate_iso_b(mlx);
		else if (mlx->projection == -1)
			rotate_para_b(mlx);
	}
}

static int	zoom(int key, t_mlx *mlx)
{
	if (key == 69)
	{
		mlx->zoom += 2;
		mlx->up_down -= 20;
		mlx->left_right -= 10;
	}
	else if (key == 78)
	{
		mlx->zoom -= 2;
		mlx->up_down += 20;
		mlx->left_right += 10;
	}
	return (1);
}

static int	reset(int key, t_mlx *mlx)
{
	if (key == 34)
	{
		mlx->projection = 0;
		mlx->rotation = 0;
		mlx->left_right = 775;
		mlx->up_down = 250;
	}
	else if (key == 35)
	{
		mlx->projection = 1;
		mlx->rotation = 0;
		mlx->up_down = 250;
		mlx->left_right = 625;
	}
	return (1);
}

static int	elsif(int key, t_mlx *mlx)
{
	if (key == 124)
		mlx->left_right += 30;
	else if (key == 123)
		mlx->left_right -= 30;
	else if (key == 125)
		mlx->up_down += 30;
	else if (key == 126)
		mlx->up_down -= 30;
	else if (key == 15)
		mlx->rotation -= 0.523559;
	else if (key == 91)
		mlx->height += 1;
	else if (key == 84)
		mlx->height -= 1;
	else if (key == 17)
		mlx->rotation += 0.523559;
	return (1);
}

int			keyhook(int key, t_mlx *mlx)
{
	if (!(reset(key, &(*mlx))))
		return (0);
	else if (key == 53)
		exit(0);
	else if (!(zoom(key, &(*mlx))))
		return (0);
	else if (key == 8)
		mlx->pcolor = 1;
	else if (key == 9)
		mlx->pcolor = 0;
	else if (!(elsif(key, &(*mlx))))
		return (0);
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	color_n_project(mlx);
	return (0);
}
