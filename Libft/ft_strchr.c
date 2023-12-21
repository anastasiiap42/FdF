/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:40:36 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/05 18:01:54 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*int	main()
{
	const char	s[] = "i wanna sleep";
	
	printf("%s ", ft_strchr(s, 't' + 256));
	printf("%s", strchr(s, 't' + 256));
}*/
