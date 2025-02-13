/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:10:32 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 20:45:20 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_pixel_put(t_list *lst, int x, int y, int color)
{
	char	*dst;
	int		offset;

	x += lst->offset_x;
	y += lst->offset_y;
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		offset = y * lst->image.l_len + x * (lst->image.b_per_p / 8);
		dst = lst->image.addr + offset;
		*(unsigned int *)dst = color;
	}
}

void	offset(t_list *lst)
{
	lst->point1.x += lst->offset_x;
	lst->point1.y += lst->offset_y;
	lst->point2.x += lst->offset_x;
	lst->point2.y += lst->offset_y;
}

void	array_free(int **array, t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst->length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
