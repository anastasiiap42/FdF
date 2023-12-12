/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/12 20:19:20 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	three_d(int *x, int *y, int z, t_list *lst)
{
	lst->angle = 0.6;
	*x = (*x - *y) * cos(lst->angle);
	*y = (*x + *y) * sin(lst->angle) - z;
	*x *= lst->zoom;
	*y *= lst->zoom;
}

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
/* 	if (lst->matrix[y1][x1] != 0)
		lst->color = 0x0000FF;
	else
		lst->color = 0xffffff; */

	// three_d(&x1, &y1, z1, lst);
	// three_d(&x2, &y2, z2, lst);

/* ------------------------------- Zoom-------------------------------- */


/* ---------------------- Drawing lines ------------------------------- */

	dx = my_abs(x2 - x1);
	dy = my_abs(y2 - y1);
	sx = greater_than(x1, x2);
	sy = greater_than(y1, y2);
	p = dx - dy;
	while (x1 != x2 || y1 != y2)
	{
		if (x1 > 0 && x1 < 1920 && y1 > 0 && y1 < 1080)
			mlx_pixel_put(lst->mlx, lst->window, x1, y1, 0xffffff);
		// if (x1 == x2 && y1 == y2)
		// 	break ;
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

	printf("%i %i\n", lst->length, lst->width);
	y = 0;
	while (y <= lst->length - 2)
	{
		x = 0;
		while (x <= lst->width - 2)
		{
			int	z1 = lst->matrix[y][x];
			int	z2 = lst->matrix[y][x + 1];
			int	z3 = lst->matrix[y + 1][x];
			xx = x;
			yy = y;
			xxx = x + 1;
			yyy = y;
			int xxxx = x;
			int yyyy = y + 1;
			three_d(&xx, &yy, z1, lst);
			three_d(&xxx, &yyy, z2, lst);
			three_d(&xxxx, &yyyy, z3, lst);
			printf("%i %i %i %i\n", xx, yy, xxx, yyy);
			if (x < lst->width)
				algorithm(xx, yy, xxx, yyy, lst);
			if (y < lst->length)
				algorithm(xx, yy, xxxx, yyyy, lst);
			x++;
		}
		y++;
	}
	printf("DONE\n");
}