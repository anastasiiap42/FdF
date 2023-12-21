/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:44:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/20 21:20:27 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		b_per_p;
	int		l_len;
	int		end;
}			t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	tx;
	int	ty;
}			t_point;

typedef struct s_math
{
	int		p;
	int		p2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}			t_math;

typedef struct s_list
{
	int				p_z;
	int				**matrix;
	int				width;
	int				length;
	int				height;

	void			*mlx;
	void			*window;
	int				zoom;
	int				color;
	double			angle;
	t_img			image;

	t_point			point1;
	t_point			point2;
	t_math			math;

	int				offset_x;
	int				offset_y;
	struct s_list	*next;
}		t_list;

void	algorithm(t_list *lst);
void	draw_lines(t_list *lst, int x, int y);
int		read_from_file(char	*argv1, t_list *lst, char *one_line);
void	my_pixel_put(t_list *lst, int x, int y, int color);
void	offset(t_list *lst);
void	array_free(int **array, t_list *lst);

#endif