/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:55:14 by apashkov          #+#    #+#             */
/*   Updated: 2023/06/06 13:32:34 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A'
			&& c <= 'Z'))
		return (0);
	return (1024);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	ar1 = 'a';
	int	ar2 = '3';

	printf("%d ", ft_isalpha(ar2));
	printf("%d", isalpha(ar2));
}*/
