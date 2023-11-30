/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_voidp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:00:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/27 12:15:02 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	length_hex(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	print_hexadec_p(unsigned long int point, int c)
{
	if (point >= 16)
	{
		print_hexadec_p(point / 16, c);
		print_hexadec_p(point % 16, c);
	}
	else if (point <= 9)
		ft_putchar(point + '0');
	else
		ft_putchar(point + c);
	return (length_hex(point));
}

int	put_voidp(unsigned long int point, int c)
{
	if (point == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		ft_putstr("0x");
		return (print_hexadec_p(point, c) + 2);
	}
}
/*#include <stdio.h>

int	main()
{
	unsigned int	n = 567387;
	void *ptr = &n;

	print_hexadec(ptr, 87);
	printf("\n%p", ptr);
}*/