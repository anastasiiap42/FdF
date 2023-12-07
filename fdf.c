/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/07 17:28:43 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algorithm(int x1, int y1, int x2, int y2, t_list *lst)
{
	float	dx;
	float	dy;
	int		p;

	x1 *= lst->zoom;
	x2 *= lst->zoom;
	y1 *= lst->zoom;
	y2 *= lst->zoom;
	int x = x1;
	int y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dx - dy;
	while (x <= x2)
	{
		mlx_pixel_put(lst->mlx, lst->window, x, y, 0xffffff);
		x++;
		if (p < 0)
			p = p + 2 * (y2 - y1);
		else
		{
			p = p + 2 * (y2 - y1) - 2 * (x2 - x1);
			y++;
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
		while (x < lst->width)
		{
			algorithm(x, y, x + 1, y, lst);
			//algorithm(y, x, y + 1, x, lst);
			x++;
		}
		y++;
	}
}