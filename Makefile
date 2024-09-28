CFLAGS= -Wall -Werror -Wextra

SRC= ./mandatory/utils_1.c \
	 ./mandatory/utils_2.c

SRC_SERVER=	./mandatory/server.c

SRC_CLIENT= ./mandatory/client.c

SRC_BONUS=	./bonus/server_bonus.c \
			./bonus/client_bonus.c

OBJ_SERVER= $(SRC_SERVER:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)
OBJ= $(SRC:.c=.o)
OBJ_BONUS= $(SRC_BONUS:.c=.o)

NAME_SEVER= server
NAME_CLIENT= client
NAME_SEVER_BONUS= server_bonus
NAME_CLIENT_BONUS= client_bonus

LIBFT_A = ./libft/libft.a
INC= -I./include

all: libft $(NAME_SEVER) $(NAME_CLIENT)

$(OBJ):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_SERVER):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_CLIENT):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_BONUS):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(NAME_SEVER): $(OBJ) $(OBJ_SERVER) $(LIBFT_A)
	cc $(CFLAGS) $(OBJ) $(OBJ_SERVER) $(LIBFT_A) -o $(NAME_SEVER)

$(NAME_CLIENT): $(OBJ) $(OBJ_CLIENT) $(LIBFT_A)
	cc $(CFLAGS) $(OBJ) $(OBJ_CLIENT) $(LIBFT_A) -o $(NAME_CLIENT)

bonus: libft $(NAME_SEVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SEVER_BONUS): $(OBJ) ./bonus/server_bonus.o $(LIBFT_A)
	cc $(CFLAGS) $(OBJ) ./bonus/server_bonus.o $(LIBFT_A) -o $@

$(NAME_CLIENT_BONUS): $(OBJ) ./bonus/client_bonus.o $(LIBFT_A)
	cc $(CFLAGS) $(OBJ) ./bonus/client_bonus.o $(LIBFT_A) -o $@

libft:
	make -C ./libft

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME_SEVER) $(NAME_CLIENT) $(NAME_SEVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: clean fclean re libft bonus all