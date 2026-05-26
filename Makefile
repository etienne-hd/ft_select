CC = cc
CFLAGS = -Wall -Wextra -Werror -g \
	-I include \
	-I library/libft \

NAME = ft_select

OBJ_DIR = .build/
SRC_DIR = source/
INC_DIR = include/

SOURCE = $(SRC_DIR)main.c \
	$(SRC_DIR)keyboard.c \
	$(SRC_DIR)ctx.c \
	$(SRC_DIR)terminal.c \
	$(SRC_DIR)select.c \
	$(SRC_DIR)render.c \
	$(SRC_DIR)event.c \
	$(SRC_DIR)signal.c \
	$(SRC_DIR)utils.c


LIBFT = library/libft/libft.a

LDFLAGS = $(SUPERPARSE) $(LIBFT) -ltermcap

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
