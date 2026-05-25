CC = cc
CFLAGS = -Wall -Wextra -Werror -g \
	-I include \
	-I library/libft 

NAME = ft_select

OBJ_DIR = .build/
SRC_DIR = source/
INC_DIR = include/

SOURCE = $(SRC_DIR)main.c \
	$(SRC_DIR)key_parser.c \
	$(SRC_DIR)ctx.c


LIBFT = library/libft/libft.a

LDFLAGS = $(SUPERPARSE) $(LIBFT)

OBJS = $(SOURCE:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C library/libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C library/libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C library/libft fclean

re: fclean all

.PHONY: all clean fclean re
