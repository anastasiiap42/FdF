/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:25:25 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 19:32:30 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stddef.h>
#include <stdio.h>*/
#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)string1;
	s2 = (unsigned char *)string2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	char	string1[] = "HELLO";
	char	string2[] = "hELLo";

	printf("%d ", ft_memcmp(string1, string2, 4));
	printf("%d", memcmp(string1, string2, 4));
 }*/