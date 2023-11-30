/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:53:14 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/30 11:11:19 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = c;
	return (s);
}
/*
int	main()
{
		char	str[] = "Before1";
		char	str2[] = "Before2";
		
		ft_memset(str, '!', 3);
		printf("%s\n", str);
		memset(str2, '!', 3);
		printf("%s", str2);
}*/
