/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:05:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/14 10:23:37 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] && f)
	{
		f(i, &s[i]);
		i++;
	}
}
/*int main()
{
	char	str[] = "abcdef";
	printf("Before: %s\n", str);
	char	*str2;
	int	i = 0;

	while (str[i])
	{
		ft_striteri(str, *f);
		printf("%c", str[i]);
	}
}*/
