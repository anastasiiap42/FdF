/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:50:47 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 12:02:39 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	white_space(char str)
{
	if (str == ' ' || (str >= '\t' && str <= '\r'))
		return (1);
	else
		return (0);
}

static int	nb_plus_minus(char str)
{
	if ((str >= '0' && str <= '9') || str == '+' || str == '-')
		return (1);
	else
		return (0);
}

long int	ft_atoi(const char *s)
{
	char		*str;
	int			i;
	int			nb;
	long int	r;

	str = (char *)s;
	i = 0;
	nb = 1;
	r = 0;
	while (str[i] && ((white_space(str[i]) == 1) || nb_plus_minus(str[i]) == 1))
	{
		if ((str[i] == '-' || str[i] == '+')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		if (str[i] == '-')
			nb = -nb;
		if (str[i] >= '0' && str[i] <= '9')
		{
			r = r * 10 + (str[i] - '0');
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (r * nb);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	str[] = "  -1234ab567";
	
	printf("ft_atoi: %d ", ft_atoi(str));
	printf("atoi: %d", atoi(str));
}*/
