/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:44:00 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 19:29:45 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stddef.h>
#include <stdio.h>
#include <string.h>*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return (string + i);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	s[] = "Hello World";
	char	*result = ft_memchr(s, 'W', 10);
	char	*result2 = memchr(s, 'W', 10);
	
	printf("%s and %s", result, result2);
}*/