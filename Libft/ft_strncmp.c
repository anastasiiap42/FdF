/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:30:36 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 19:44:23 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (((unsigned char)s1[i] != (unsigned char)s2[i]))
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	s1[] = "heLlo";
	char	s2[] = "hellooo";
	unsigned int	i = 4;

	printf("%d ", ft_strncmp(s1, s2, i));	
	printf("%d", strncmp(s1, s2, i));
}*/
