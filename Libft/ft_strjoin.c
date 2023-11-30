/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:22:31 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/15 13:23:06 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	x;
	size_t	i;

	x = 0;
	i = ft_strlen(s1);
	new = (char *)malloc((i + ft_strlen(s2) + 1) * sizeof(char));
	if (!(new))
		return (NULL);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		new[i] = s2[x];
		i++;
		x++;
	}
	new[i] = '\0';
	return (new);
}
/*#include <stdio.h>
int	main()
{
	const char	s1[] = "\0";
	const char	s2[] = "dolor sit amet";

	printf("%s + %s = %s", s1, s2, ft_strjoin(s1, s2));
}*/