/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:43:33 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/27 12:29:59 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_type(const char *input, va_list args, int i)
{
	if (*input == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*input == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*input == 'p')
		i += put_voidp(va_arg(args, unsigned long int), 87);
	else if (*input == 'd' || *input == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*input == 'u')
		i += ft_put_u(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += print_hexadec(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		i += print_hexadec(va_arg(args, unsigned int), 55);
	else if (*input == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	va_start(args, input);
	i = 0;
	if (*input == '\0')
		return (-1);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i = define_type(input, args, i);
		}
		else
			i += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (i);
}
/*#include <stdio.h>

int	main()
{
	unsigned int	n = 567387;
	void *ptr = &n;
	int	d = -2147483648;

	printf("\n%d\n", ft_printf("%c,%s,%p,%d,%i,%u,%x,%X,%%", 
	'&', "hey", ptr, 423, d, 417687283, 45667, 45667));
	printf("\n%d\n", printf("%c %s %p %d %i %u %x %X %%", 
	'&', "hey", ptr, 423, d, 417687283, 45667, 45667));
}*/