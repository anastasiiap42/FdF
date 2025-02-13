/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:37:26 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 18:40:44 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (-1);
	while (string[i])
		i++;
	return (i);
}
/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[] = "hello";

	printf("%zu ", ft_strlen(str));
	printf("%lu", strlen(str));
}*/
