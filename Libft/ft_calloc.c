/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:16:07 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/19 12:44:01 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*f;

	if (nmemb == 0)
		return (malloc(0));
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	f = malloc(nmemb * size);
	if (f == NULL)
		return (NULL);
	else
		ft_bzero(f, nmemb * size);
	return (f);
}
/*int main() 
{
   int n, i, *ptr, sum = 0;
   printf("Enter number of elements: ");
   scanf("%d", &n);

   ptr = (int*) ft_calloc(n, sizeof(int));
   if(ptr == NULL) {
     printf("Error! memory not allocated.");
     exit(0);
   }

   printf("Enter elements: ");
   for(i = 0; i < n; ++i) {
     scanf("%d", ptr + i);
     sum += *(ptr + i);
   }

   printf("Sum = %d", sum);
   free(ptr);
   return 0;
}*/
