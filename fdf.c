/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/16 13:18:42 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	greater_than(int a, int b)
{
	if (a < b)
		return (1);
	else 
		return (-1);
}

void	three_d(t_list *lst, int *x, int *y)
{
	lst->angle = 0.6;
	*x = (*x - *y) * cos(lst->angle);
	*y = (*x + *y) * sin(lst->angle) - lst->p_z;
}

void	algorithm(int x1, int y1, int x2, int y2, t_list *lst)
{
	int		p;
	int		p2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;

/* --------------------- Color ------------------------------------ */
	printf("[%d][%d]\n", y1, x1);
	if (lst->p_z != 0)
		lst->color = 0x0000FF;
	else
		lst->color = 0xffffff;


	zoom(&x1, &y1, &x2, &y2, lst);
/* ---------------------- Drawing a line ------------------------------- */

	dx = my_abs(x2 - x1);
	dy = my_abs(y2 - y1);
	sx = greater_than(x1, x2);
	sy = greater_than(y1, y2);
	p = dx - dy;
	while (1)
	{
		my_pixel_put(lst, x1, y1, lst->color);
		if (x1 == x2 && y1 == y2)
			break ;
		p2 = 2 * p;
		if (p2 > -dy)
		{
			p -= dy;
			x1 += sx;
		}
		if (p2 < dx)
		{
			p += dx;
			y1 += sy;
		}
	}
}

void	draw_lines(t_list *lst)
{
	int	x;
	int	y;
	int	xx;
	int	yy;
	int	xxx;
	int	yyy;
	int	xxxx;
	int	yyyy;

	y = 0;
	while (y <= lst->length)
	{
		x = 0;
		while (x <= lst->width)
		{
			lst->p_z = lst->matrix[y][x];
			xx = x;
			yy = y;
			xxx = x + 1;
			yyy = y;
			xxxx = x;
			yyyy = y + 1;
			three_d(lst, &xx, &yy);
			three_d(lst, &xxx, &yyy);
			three_d(lst, &xxxx, &yyyy);
			if (x < lst->width)
				algorithm(xx, yy, xxx, yyy, lst);
				//algorithm(x, y, x + 1, y, lst);
			if (y < lst->length)
				algorithm(xx, yy, xxxx, yyyy, lst);
				//algorithm(x, y, x, y + 1, lst);
			x++;
		}
		y++;
	}
	printf("DONE\n");
}