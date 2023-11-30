/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:16:58 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/27 10:23:10 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checklength(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_put_u(unsigned int n)
{
	unsigned int	d;

	if (n > 9)
	{
		ft_put_u(n / 10);
	}
	d = n % 10 + '0';
	write(1, &d, 1);
	return (ft_checklength(n));
}
/*
int	main()
{
	unsigned int d = 4294967295;

	printf("\n%d", ft_put_u(d));
}*/