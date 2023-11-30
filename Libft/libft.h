/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:02:00 by apashkov          #+#    #+#             */
/*   Updated: 2023/11/15 12:25:06 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char		*free_array(char **array);
long int	ft_atoi(const char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *string1, const void *string2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *string, int ch);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dst, const char *src, size_t s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *string);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*ft_strnstr(const char *str, const char *to_find, size_t s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrchr(const char *string, int ch);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
