/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:02 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 18:42:42 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t s)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < s)
		i++;
	return (ft_strlcpy(&dst[i], src, s - i) + i);
}
/*#include <bsd/string.h>
#include <stdio.h>

int	main()
{
	const char	src[] = "something ";
	char	dest[] = "whatever ";

	printf("%zu", ft_strlcat(dest, src, 2));
	printf("%zu", strlcat(dest, src, 2));
}*/