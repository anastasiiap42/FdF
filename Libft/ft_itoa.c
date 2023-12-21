/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:58 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/15 10:58:03 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0 || n < 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*string(char *str, size_t len, int st, int n)
{
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (st == 0)
		str[0] = '0';
	else if (st < 0)
	{
		str[0] = '-';
		if (st == -2147483648)
			str[1] = '2';
	}
	str[nb_digits(st)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		st;

	st = n;
	len = nb_digits(n);
	if (n == -2147483648)
		n = n % 1000000000;
	if (n < 0)
		n = -n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str = string(str, len, st, n);
	return (str);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(int c, char **v)
{
	if (c > 0) {}

	printf("%s\n", ft_itoa(atoi(v[1])));
}*/
