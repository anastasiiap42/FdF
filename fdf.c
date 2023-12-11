/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/11 19:53:50 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
void	three_d(float x, float y, int z)
{
	x = 
}
 */
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

	if (lst->matrix[y1][x1])
		lst->color = 0x0000FF;
	else
		lst->color = 0xffffff;
	
	x1 *= lst->zoom;
	x2 *= lst->zoom;
	y1 *= lst->zoom;
	y2 *= lst->zoom;
	
	dx = my_abs(x2 - x1);
	dy = my_abs(y2 - y1);
	sx = greater_than(x1, x2);
	sy = greater_than(y1, y2);
	p = 2 * dx - dy;
	while (1)
	{
		mlx_pixel_put(lst->mlx, lst->window, x1, y1, lst->color);
		if (x1 == x2 && y1 == y2)
			break ;
		p2 = 2 * p;
		if (p2 > dy)
		{
			p += dy;
			x1 += sx;
		}
		else if (p2 < dx)
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

	y = 0;
	while (y < lst->length)
	{
		x = 0;
		while (x <= lst->width)
		{
			if (x < lst->width)
				algorithm(x, y, x + 1, y, lst);
			if (y < lst->length)
				algorithm(x, y, x, y + 1, lst);
			x++;
		}
		algorithm(x, y, x, y + 1, lst);
		y++;
	}
}