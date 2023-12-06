/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:35 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/06 19:31:57 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algorithm(int x1, int y1, int x2, int y2, t_list *lst)
{
	int		x;
	float	dx;
	float	dy;
	int		p;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dx - dy;
	while (x <= x2)
	{
		mlx_pixel_put(lst->mlx, lst->window, x, y, 0xffffff);
		x++;
		if (p < 0)
			p = p + 2 * ();
		else
		{
			p = p + 2 * () - 2 * ();
			y++;
		}
	}
}