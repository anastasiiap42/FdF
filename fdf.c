/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/18 16:02:35 by apashkov         ###   ########.fr       */
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

void	zoom_and_3d(t_list *lst)
{
	lst->point1.z = lst->matrix[lst->point1.y][lst->point1.x];
	lst->point2.z = lst->matrix[lst->point2.y][lst->point2.x];
	if (lst->point1.z != 0)
		lst->color = 0xcc1100;
	else
		lst->color = 0xffffff;
	lst->point1.x *= lst->zoom;
	lst->point1.y *= lst->zoom;
	lst->point2.x *= lst->zoom;
	lst->point2.y *= lst->zoom;
	lst->point1.x = (lst->point1.x - lst->point1.y) * cos(lst->angle);
	lst->point1.y = (lst->point1.x + lst->point1.y) * sin(lst->angle);
	lst->point1.y -= lst->point1.z;
	lst->point2.x = (lst->point2.x - lst->point2.y) * cos(lst->angle);
	lst->point2.y = (lst->point2.x + lst->point2.y) * sin(lst->angle);
	lst->point2.y -= lst->point2.z;
}

void	algorithm(t_list *lst)
{
	zoom_and_3d(lst);
	lst->math.dx = my_abs(lst->point2.x - lst->point1.x);
	lst->math.dy = my_abs(lst->point2.y - lst->point1.y);
	lst->math.sx = greater_than(lst->point1.x, lst->point2.x);
	lst->math.sy = greater_than(lst->point1.y, lst->point2.y);
	lst->math.p = lst->math.dx - lst->math.dy;
	while (!(lst->point1.x == lst->point2.x && lst->point1.y == lst->point2.y))
	{
		my_pixel_put(lst, lst->point1.x, lst->point1.y, lst->color);
		lst->math.p2 = 2 * lst->math.p;
		if (lst->math.p2 > -lst->math.dy)
		{
			lst->math.p -= lst->math.dy;
			lst->point1.x += lst->math.sx;
		}
		if (lst->math.p2 < lst->math.dx)
		{
			lst->math.p += lst->math.dx;
			lst->point1.y += lst->math.sy;
		}
	}
}

void	draw_lines(t_list *lst, int x, int y)
{
	while (++y < lst->length)
	{
		x = -1;
		while (++x < lst->width)
		{
			if (x < lst->width - 1)
			{
				lst->point1.x = x;
				lst->point2.x = x + 1;
				lst->point1.y = y;
				lst->point2.y = y;
				algorithm(lst);
			}
			if (y < lst->length - 1)
			{
				lst->point1.x = x;
				lst->point2.x = x;
				lst->point1.y = y;
				lst->point2.y = y + 1;
				algorithm(lst);
			}
		}
	}
}
