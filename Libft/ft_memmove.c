/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:04:06 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/21 09:53:19 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*src2;
	char		*dst2;

	dst2 = dst;
	src2 = src;
	if (!dst && !src)
		return (NULL);
	if (dst2 < src2)
		ft_memcpy(dst2, src2, n);
	else
	{
		while (n--)
			dst2[n] = src2[n];
	}
	return (dst);
}
/*int	main()
{
	char	input[20] = "Hello_world";
	char	*dest;

	dest = ft_memmove(input + 5, input, 6 * sizeof(char));
	printf("%s", dest);
}*/