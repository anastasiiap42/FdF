/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:42:14 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 10:33:34 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
		int	c = 127;

		printf("%d ", ft_isprint(c));
		printf("%d", isprint(c));
}*/
