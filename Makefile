.SILENT:

NAME := fdf

BONUS_NAME := fdf_bonus

COMPILER := cc

FLAGS := -Wall -Wextra -Werror -g

SRCS := read_file.c\
fdf.c\
main.c\
fdf_utils.c

BONUS_SRCS := read_file_bonus.c\
fdf_bonus.c\
main_bonus.c\
fdf_utils_bonus.c

LDFLAGS = -Lminilibx-linux -LLibft -lmlx -lXext -lX11 -lm -lft

OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) fdf.h
	@cd Libft && $(MAKE) --no-print-directory
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) ./Libft/libft.a

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) fdf_bonus.h
	@cd Libft && $(MAKE) --no-print-directory
	$(COMPILER) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LDFLAGS) ./Libft/libft.a

clean:
	@cd Libft/ && $(MAKE) fclean --no-print-directory
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
