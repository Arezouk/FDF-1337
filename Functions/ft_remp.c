/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hessabra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:21:33 by hessabra          #+#    #+#             */
/*   Updated: 2019/01/05 21:26:40 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	ft_remp(t_mlx *a, t_coord *b, t_coord *c)
{
	a->dx = abs((c->x + a->left_right) - (b->x + a->left_right));
	a->dy = abs((c->y + a->up_down) - (b->y + a->up_down));
	if ((b->x + a->left_right) < (c->x + a->left_right))
		a->xi = 1;
	else
		a->xi = -1;
	if ((b->y + a->up_down) < (c->y + a->up_down))
		a->yi = 1;
	else
		a->yi = -1;
	a->x = b->x + a->left_right;
	a->y = b->y + a->up_down;
	return (*a);
}
