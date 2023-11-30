/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:10:36 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 09:28:55 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!(dest))
		return (NULL);
	i = 0;
	while (((char *)s)[i] != '\0')
	{
		dest[i] = ((char *)s)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src = "pryvit";

	printf("%s\n", ft_strdup(src));
	printf("%s", strdup(src));
}*/
