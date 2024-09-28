CFLAGS= -Wall -Werror -Wextra

SRC=	./mandatory/utils_1.c \
	 	./mandatory/utils_2.c \
		./mandatory/utils_3.c

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
LIBPRINTF= ./libprintf/libftprintf.a

INC= -I./include

all: libftprintf $(NAME_SEVER) $(NAME_CLIENT)

$(OBJ):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_SERVER):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_CLIENT):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_BONUS):%.o:%.c
	cc $(CFLAGS) $(INC) -c $< -o $@

$(NAME_SEVER): $(OBJ) $(OBJ_SERVER) $(LIBPRINTF)
	cc $(CFLAGS) $(OBJ) $(OBJ_SERVER) $(LIBPRINTF) -o $(NAME_SEVER)

$(NAME_CLIENT): $(OBJ) $(OBJ_CLIENT)
	cc $(CFLAGS) $(OBJ) $(OBJ_CLIENT) $(LIBPRINTF) -o $(NAME_CLIENT)

bonus: libftprintf $(NAME_SEVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SEVER_BONUS): $(OBJ) ./bonus/server_bonus.o $(LIBPRINTF)
	cc $(CFLAGS) $(OBJ) $(LIBPRINTF) ./bonus/server_bonus.o -o $@

$(NAME_CLIENT_BONUS): $(OBJ) ./bonus/client_bonus.o $(LIBPRINTF)
	cc $(CFLAGS) $(OBJ) $(LIBPRINTF) ./bonus/client_bonus.o -o $@

libftprintf:
	make -C ./libprintf

clean:
	make clean -C libprintf/
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS)

fclean: clean
	make fclean -C libprintf/
	rm -f $(NAME_SEVER) $(NAME_CLIENT) $(NAME_SEVER_BONUS) $(NAME_CLIENT_BONUS) $(LIBPRINTF)

re: fclean all

.PHONY: clean fclean re libftprintf bonus all