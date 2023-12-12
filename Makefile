.SILENT:

NAME := fdf

COMPILER := cc

FLAGS := -Wall -Wextra -Werror -g

SRCS := read_file.c\
fdf.c

LDFLAGS = -Lminilibx-linux -LLibft -lmlx -lXext -lX11 -lm -lft

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) fdf.h
	@cd Libft && $(MAKE) --no-print-directory
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) ./Libft/libft.a

clean:
	@cd Libft/ && $(MAKE) fclean --no-print-directory
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
