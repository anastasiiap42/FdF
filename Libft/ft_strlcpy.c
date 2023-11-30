/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:48:27 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/15 11:12:55 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	arr[] = "World                ";
	char	dest[5] = "Hello";

	printf("%zu ", ft_strlcpy(dest, arr, 0));
	printf("%zu", strlcpy(dest, arr, 0));
}*/
