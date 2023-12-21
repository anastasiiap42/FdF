/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:54:18 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 18:45:30 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	check_nb_str(char *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		counter = 1;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				counter++;
			i++;
		}
		i++;
	}
	return (counter);
}

static char	*put_words(char *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	str = ft_substr(s - len, 0, len);
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	size_t	len;
	int		i;

	i = 0;
	arr = (char **)malloc((check_nb_str(s, c) + 1) * sizeof(char *));
	if (!(arr))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[i] = put_words(s, c);
			if (!(arr[i]))
				return (free_array(arr), NULL);
			len = ft_strlen(arr[i]);
			i++;
			s = s + len;
		}
	}
	arr[i] = NULL;
	return (arr);
}

/*
#include <stdio.h>
int main(int argc, char **argv) {
	char **split = ft_split(argv[1], argv[2][0]);

	for (int i = 0; split[i]; i++)
	{
		printf("'%s'\n", split[i]);
	}
	free_array(split);
}*/
/*

int	main()
{
    char    str[] = "hellooo world  ";
    int    n = 0;
    char    **arr;
    char    c = ' ';

    arr = ft_split(str, c);
    printf("The number of strings: %zu\n", check_nb_str(str, c));
    while (n <= check_nb_str(str, c))
	{
        printf("%s\n", arr[n++]);
	}
}*/