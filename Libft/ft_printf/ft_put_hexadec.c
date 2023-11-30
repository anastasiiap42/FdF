/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:00:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/26 09:08:06 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	length_hex(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	print_hexadec(unsigned int n, int c)
{
	if (n >= 16)
	{
		print_hexadec(n / 16, c);
		print_hexadec(n % 16, c);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar(n + c);
	return (length_hex(n));
}
/*#include <stdio.h>

int	main()
{
	unsigned int	n = 238555;

	printf("\n%d", print_hexadec(n, 55));
}*/
	/*char			*str;
	size_t			l;
	unsigned int	st;

	st = n;
	l = length_hex(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (0);
	while (l--)
	{
		if ((n % 16) < 10)
			str[l] = (n % 16) + 48;
		else
			str[l] = (n % 16) + c;
		n = n / 16;
	}
	str[length_hex(st)] = '\0';
	free(str);
	return (length_hex(st));*/