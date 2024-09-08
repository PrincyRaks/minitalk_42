CFLAGS= -Wall -Werror -Wextra -g

SRC_SERVER= ./mandatory/server.c \
			./mandatory/utils_1.c \
			./mandatory/utils_2.c

SRC_CLIENT= ./mandatory/client.c \
			./mandatory/utils_1.c \
			./mandatory/utils_2.c

OBJ_SERVER= $(SRC_SERVER:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)

NAME_SEVER= server
NAME_CLIENT= client
LIBFT_A = ./libft/libft.a

all: libft $(NAME_SEVER) $(NAME_CLIENT)

$(OBJ_SERVER):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT):%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME_SEVER): $(OBJ_SERVER) $(LIBFT_A)
	cc $(CFLAGS) $(OBJ_SERVER) $(LIBFT_A) -o $(NAME_SEVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT_A)
	cc $(CFLAGS) $(OBJ_CLIENT) $(LIBFT_A) -o $(NAME_CLIENT)

libft:
	make -C ./libft

clean:
	make clean -C libft/
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME_SEVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re libft all