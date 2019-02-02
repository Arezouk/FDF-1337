/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:57:29 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/17 22:03:03 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*get_value(char *holder)
{
	t_coord	*point;

	point = (t_coord *)malloc(sizeof(t_coord));
	point->value = ft_atoi(holder);
	return (point);
}

t_line		*stock_line(char **holder, int i)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->points = (t_coord **)malloc(sizeof(t_coord *) * (i + 1));
	i = 0;
	while (holder[i])
	{
		line->points[i] = get_value(holder[i]);
		i++;
	}
	line->points[i] = NULL;
	line->next = NULL;
	return (line);
}

static int	holde(int i, char **holder)
{
	while (holder[i])
		i++;
	return (i);
}

t_line		*read_and_stock(int fd, t_line *line)
{
	char	**holder;
	char	*tab;
	int		i;
	int		j;
	t_line	*temp;

	i = 0;
	while (get_next_line(fd, &tab))
	{
		holder = ft_strsplit(tab, ' ');
		j = holde(j, holder);
		linerror(j);
		if (i++ == 0)
		{
			line = stock_line(holder, j);
			temp = line;
			continue ;
		}
		line->next = stock_line(holder, j);
		line = line->next;
	}
	free(holder);
	(j == 0) ? temp = NULL : temp;
	return (temp);
}

int			main(int argc, char *argv[])
{
	t_mlx	*mlx;
	int		ret;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx = initialize(mlx);
	if (argc == 2)
	{
		error(argv[1], &ret, mlx->line);
		mlx->line = read_and_stock(ret, mlx->tmp);
		error(argv[1], &ret, mlx->line);
		close(ret);
		mlx->mlx_ptr = mlx_init();
		mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, 1600, 1200, "le window");
		rotate_iso(mlx);
		mlx_hook(mlx->mlx_win, 2, 1, keyhook, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
	return (0);
}
