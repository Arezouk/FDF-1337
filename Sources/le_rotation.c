/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 04:24:56 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/11 22:51:55 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	le_rotation(int *x1, int *y1, double rotation)
{
	int		x0;
	int		y0;

	x0 = *x1;
	y0 = *y1;
	*x1 = x0 * cos(rotation) - y0 * sin(rotation);
	*y1 = x0 * sin(rotation) + y0 * cos(rotation);
}

void	isometric_rotation(int *x1, int *y1, int z)
{
	int		x0;
	int		y0;

	x0 = *x1;
	y0 = *y1;
	*x1 = (x0 - y0) * cos(0.523559);
	*y1 = -z + (x0 + y0) * sin(0.523559);
}
