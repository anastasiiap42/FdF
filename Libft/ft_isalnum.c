/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:19:29 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 10:21:51 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || ((c >= 'A') && (c <= 'Z'))
		|| (c >= '0' && c <= '9'))
		return (8);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>

int	main()
{
		int	c = '%';

		printf("%d ", ft_isalnum(c));
		printf("%d", isalnum(c));
}*/
