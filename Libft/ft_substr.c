/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:43:55 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 09:24:57 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	subs = (char *)malloc(len + 1);
	if (!(subs))
		return (NULL);
	i = 0;
	while (*s && start < ft_strlen(s) && i < len)
	{
		subs[i++] = ((char *)s)[start++];
	}
	subs[i] = '\0';
	return (subs);
}
/*#include <stdio.h>
int	main()
{
	const char	s[] = "Dobroho ranku";
	printf("%s\n", ft_substr(s, 3, 4));
}*/