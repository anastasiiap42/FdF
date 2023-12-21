/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:51:39 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 17:21:53 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

char	*ft_strrchr(const char *string, int ch)
{
	unsigned int	len;

	len = ft_strlen((char *)string);
	if ((char) ch == '\0')
		return (&((char *)string)[len]);
	while (len--)
	{
		if (string[len] == (char) ch)
			return (&((char *)string)[len]);
	}
	return (NULL);
}
/*
int	main()
{
	char	string[] = "i wanna sleep";
	
	printf("%s ", ft_strrchr(string, 'e'));
	printf("%s", strrchr(string, 'e'));
}*/
