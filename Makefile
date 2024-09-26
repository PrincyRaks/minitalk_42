CFLAGS= -Wall -Werror -Wextra

SRC= ./mandatory/utils_1.c \
	 ./mandatory/utils_2.c

SRC_SERVER=	./mandatory/server.c

SRC_CLIENT= ./mandatory/client.c

OBJ_SERVER= $(SRC_SERVER:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)
OBJ= $(SRC:.c=.o)

NAME_SEVER= server
NAME_CLIENT= client
LIBFT_A = ./libft/libft.a
INC= -I./include

all: libft $(NAME_SEVER) $(NAME_CLIENT)

$(OBJ):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_SERVER):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_CLIENT):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(NAME_SEVER): $(OBJ) $(OBJ_SERVER) $(LIBFT_A)
	cc $(CFLAGS) $(INC) $(OBJ) $(OBJ_SERVER) $(LIBFT_A) -o $(NAME_SEVER)

$(NAME_CLIENT): $(OBJ) $(OBJ_CLIENT) $(LIBFT_A)
	cc $(CFLAGS) $(INC) $(OBJ) $(OBJ_CLIENT) $(LIBFT_A) -o $(NAME_CLIENT)

libft:
	make -C ./libft

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME_SEVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re libft all