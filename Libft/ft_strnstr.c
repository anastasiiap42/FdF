/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:43:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/11 10:29:12 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t s)
{
	size_t	i;
	size_t	l;
	char	*string;

	string = (char *)str;
	if (to_find[0] == '\0')
		return (string);
	i = 0;
	while (string[i] && i < s)
	{
		l = 0;
		while (string[i + l] == to_find[l] && to_find[l] && (i + l) < s)
			l++;
		if (to_find[l] == '\0')
			return (&string[i]);
		i++;
	}
	return (NULL);
}
/*#include <bsd/string.h>

int	main()
{
	char	str[] = "aaabcabcd";
	char	to_find[] = "abcd";

	printf(".%s. ", ft_strnstr(str, to_find, 9));
	printf(".%s.\n", strnstr(str, to_find, 9));
}*/