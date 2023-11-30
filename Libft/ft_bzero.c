/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:26:41 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 10:46:52 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = '\0';
}
/*
#include <strings.h>
#include <stdio.h>

int main()
{
    char    str[] = "Before1";
    char    str2[] = "Before2";

    ft_bzero(str, 5);
    printf("%s\n", str);
    bzero(str2, 5);
    printf("%s", str2);
}*/
