/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:44:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/07 16:36:36 by apashkov         ###   ########.fr       */
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

typedef struct s_list
{
	int				p_x;
	int				p_y;
	int				**matrix;
	int				width;
	int				length;

	void			*mlx;
	void			*window;
	void			*image;
	int				zoom;

	struct s_list	*next;
}		t_list;

void	algorithm(int x1, int y1, int x2, int y2, t_list *lst);
void	draw_lines(t_list *lst);

#endif