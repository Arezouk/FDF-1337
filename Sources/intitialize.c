/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intitialize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 04:05:01 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/07 23:40:38 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 560, 60, 0xE6E6FA, " 0xE6E6FA");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 650, 60, 0xE6E6FA, " > ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 670, 60, 0x8B008B, " 0x8B008B");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 400,
			85, 0x002cb72, "BlueGradient   : ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 560, 85, 0xADD8E6, " 0xADD8E6");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 650, 85, 0xADD8E6, " > ");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 670, 85, 0x191970, " 0x191970");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 550, 10, 0x002cb72,
			"ChangeColor : C / V");
}

void		window_initialize(t_mlx *mlx)
{
	colorc(&(*mlx));
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 10, 10, mlx->xs, "ZoomIn   : +");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 10, 30, mlx->ys, "ZoomOut  : -");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 200, 20,
			mlx->ys, "Mouvment : <   >");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 200, 10,
			mlx->xs, "             ^");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 200, 30,
			mlx->xs, "             v");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 400, 10,
			mlx->ys, "RotLeft  : T");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 400, 30,
			mlx->xs, "RotRight : R");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 10, 60,
			mlx->xs, "ResetIso  : I");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 10, 85,
			mlx->ys, "ResetPara : P");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 200, 60,
			mlx->xs, "IncreaseHight : 8");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 200, 85,
			mlx->ys, "DecreaceHight : 2");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 400, 60,
			0x002cb72, "PurpleGradient : ");
	color(&(*mlx));
}

t_mlx		*initialize(t_mlx *mlx)
{
	mlx->projection = 0;
	mlx->left_right = 775;
	mlx->up_down = 250;
	mlx->height = 1;
	mlx->zoom = 20;
	mlx->rotation = 0;
	mlx->color = 0x00ff2b;
	mlx->hcolor = 0xE6E6FA;
	return (mlx);
}
