/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:12:52 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/15 12:57:05 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	f;
	size_t	l;
	int		i;

	f = 0;
	i = 0;
	l = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[f]) && f <= l)
		f++;
	while (l >= f && ft_strchr(set, s1[l - 1]) && l)
		l--;
	if (!(l > f))
		return (ft_calloc(1, sizeof(char)));
	str = (char *)malloc((sizeof(char) * (l - f + 1)));
	if (!(str))
		return (NULL);
	while (f < l)
		str[i++] = s1[f++];
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char *s1 = " .helloo...";
    char *s2 = "/. ";
	char *ret = ft_strtrim(s1, s2);

	printf("%s\n", ret);
}*/
