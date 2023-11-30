/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:44:53 by apashkov          #+#    #+#             */
/*   Updated: 2023/09/27 12:14:10 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int		print_hexadec(unsigned int n, int c);
int		ft_put_u(unsigned int n);
int		put_voidp(unsigned long int point, int c);
int		ft_printf(const char *input, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);

#endif