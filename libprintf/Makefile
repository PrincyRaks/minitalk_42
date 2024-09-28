CFLAGS= -Wall -Wextra -Werror
SRC= format_code.c \
	ft_printf.c
	
UTILS_SRCS= ./utils/ft_print_hexa.c \
	./utils/ft_putchar_fd.c \
	./utils/ft_putnbr_base.c \
	./utils/ft_putnbr_uint.c \
	./utils/ft_putstr_fd.c \
	./utils/ft_strlen.c \
	./utils/ft_putnbr_int.c

OBJS= $(SRC:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)
NAME= libftprintf.a

all: $(NAME)

$(OBJS):%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(UTILS_OBJS):%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(UTILS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(UTILS_OBJS)

clean:
	@rm -f $(OBJS) $(UTILS_OBJS)

fclean: clean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclean re bonus all
