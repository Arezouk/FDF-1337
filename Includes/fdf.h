/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:44:10 by arezouk           #+#    #+#             */
/*   Updated: 2019/01/17 21:58:59 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define BUFF_SIZE 1024

typedef struct	s_coord
{
	int			color;
	int			x;
	int			y;
	int			value;
}				t_coord;

typedef struct	s_line
{
	struct s_line	*next;
	t_coord			**points;
}				t_line;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_line	*line;
	t_line	*tmp;
	float	zoom;
	float	rotation;
	float	height;
	int		hcolor;
	int		color;
	int		holder;
	int		left_right;
	int		up_down;
	int		x;
	int		y;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		xs;
	int		ys;
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		error;
	int		pcolor:1;
	int		projection:1;
}				t_mlx;

void			linerror(int j);
void			rotate_iso_b(t_mlx *mlx);
void			rotate_para_b(t_mlx *mlx);
void			window_initialize(t_mlx *mlx);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *nptr);
char			**ft_strsplit(char *s, char c);
void			ft_putstr(char const *s);
void			ft_strdel(char **as);
int				keyhook(int	key, t_mlx *mlx);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
int				get_next_line(const int fd, char **line);
t_mlx			ft_remp(t_mlx *a, t_coord *b, t_coord *c);
void			rotate_iso(t_mlx *mlx);
void			rotate_para(t_mlx *mlx);
t_coord			*get_value(char *holder);
t_line			*stock_line(char **holder, int i);
t_line			*read_and_stock(int	fd, t_line *line);
void			le_rotation(int *x1, int *y1, double rotation);
void			isometric_rotation(int *x1, int *y1, int z);
void			isometric(t_mlx *mlx);
void			rotate(t_mlx *mlx);
t_mlx			*initialize(t_mlx *mlx);
void			draw_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2,
		int color);
t_line			*create_coordinates(t_line *line, int zoom);
void			colorc(t_mlx *mlx);
void			error(char *gv, int *ret, t_line *line);
#endif
