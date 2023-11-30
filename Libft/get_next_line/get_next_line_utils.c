/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:09:15 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/12 16:23:25 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int ch)
{
	if (!string)
		return (NULL);
	while ((*string))
	{
		if (*string == (char)ch)
			return ((char *)string);
		string++;
	}
	if ((char)ch == '\0')
		return ((char *)string);
	return (NULL);
}

size_t	ft_strlen(const char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		x;

	x = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[++x])
		new[x] = s1[x];
	while (*s2)
		new[x++] = *s2++;
	new[x] = '\0';
	free(s1);
	return (new);
}

char	*ft_strtrim(char *s1, char set)
{
	char	*str;
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	if (!s1 || !s1[0])
		return (NULL);
	while (s1[i] && s1[i] != set)
		i++;
	if (s1[i] == set)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i--)
		str[l++] = *s1++;
	str[l] = '\0';
	return (str);
}

char	*ft_strtrim_the_rest(char *s1, char set)
{
	char	*str;
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	if (!s1 || !set || !s1[0])
		return (free(s1), NULL);
	while (s1[i] && s1[i] != set)
		i++;
	if (s1[i] == set)
		i++;
	str = (char *)malloc((ft_strlen(s1) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
		str[l++] = s1[i++];
	str[l] = '\0';
	free(s1);
	return (str);
}
