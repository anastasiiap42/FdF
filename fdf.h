/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:44:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/16 13:19:17 by apashkov         ###   ########.fr       */
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

typedef struct s_list
{
	int				p_z;
	int				**matrix;
	int				width;
	int				length;

	void			*mlx;
	void			*window;
	int				zoom;
	int				color;
	double			angle;
	t_img			image;

	int				offset_x;
	int				offset_y;
	struct s_list	*next;
}		t_list;

void	algorithm(int x1, int y1, int x2, int y2, t_list *lst);
void	draw_lines(t_list *lst);
void	read_from_file(char	*argv1, t_list *lst);
void	my_pixel_put(t_list *lst, int x, int y, int color);
void	zoom(int *x1, int *y1, int *x2, int *y2, t_list *lst);
void	offset(int x1, int y1, int x2, int y2, t_list *lst);

#endif