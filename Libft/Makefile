.SILENT:

NAME := libft.a

COMPILER := cc

FLAGS := -Wall -Wextra -Werror -g

SRCS := ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_printf/ft_printf.c\
ft_printf/ft_putchar.c\
ft_printf/ft_put_hexadec.c\
ft_printf/ft_putnbr.c\
ft_printf/ft_putstr.c\
ft_printf/ft_put_u.c\
ft_printf/ft_put_voidp.c\
get_next_line.c\
ft_swap.c

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) 

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@ -I./
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
