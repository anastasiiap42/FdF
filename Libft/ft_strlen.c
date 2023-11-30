/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:37:26 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/11 10:28:48 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}
/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[] = "hello";

	printf("%zu ", ft_strlen(str));
	printf("%lu", strlen(str));
}*/
