/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:10:32 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/16 13:19:41 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_list *lst, int x, int y, int color)
{
	char	*dst;
	int		offset;
	/* int		xx;
	int		yy;
	
	lst->angle = 0.6;
	xx = (x - y) * cos(lst->angle);
	yy = (x + y) * sin(lst->angle) - lst->p_z; */
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		offset = y * lst->image.l_len + x * (lst->image.b_per_p / 8);
		dst = lst->image.addr + offset;
		*(unsigned int *)dst = color; 
	}
}

void	zoom(int *x1, int *y1, int *x2, int *y2, t_list *lst)
{
	*x1 *= lst->zoom;
	*x2 *= lst->zoom;
	*y1 *= lst->zoom;
	*y2 *= lst->zoom;
}

void	offset(int x1, int y1, int x2, int y2, t_list *lst)
{
	x1 += lst->offset_x;
	x2 += lst->offset_x;
	y1 += lst->offset_y;
	y2 += lst->offset_y;
}
