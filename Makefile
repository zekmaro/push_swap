NAME	:= push_swap
BNS		:= checker
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g
LIBS	:= libft/libft.a ft_printf/libftprintf.a
HEADER	:= push_swap.h

SRC		:=	push_swap.c	\
			parsing.c	\
			sorting.c	\
			methods.c	\
			utils.c 	\
			utils2.c	\
			utils3.c	\
			utils4.c	\
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			sort_three.c \
			sort_five.c \
			fast_sorts.c

SRC_BNS	:= 	bonus/checker.c	\
			parsing.c	\
			sorting.c	\
			methods.c	\
			utils.c 	\
			utils2.c	\
			utils3.c	\
			utils4.c	\
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			sort_three.c \
			sort_five.c \
			fast_sorts.c \
			bonus/methods_bonus.c

OBJ		:= $(SRC:%.c=%.o)
OBJ_BNS	:= $(SRC_BNS:%.c=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ) $(HEADER)
	make -C ft_printf all
	make -C libft all
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

bonus	: $(BNS)

$(BNS)	: $(OBJ_BNS) $(HEADER)
	make -C ft_printf all
	make -C libft all
	$(CC) $(OBJ_BNS) $(LIBS) -o $(BNS)

clean	:
	make -C ft_printf clean
	make -C libft clean
	rm -f $(OBJ) $(OBJ_BNS)

fclean	:
	make -C ft_printf fclean
	make -C libft fclean
	rm -f $(OBJ) $(OBJ_BNS) $(NAME) $(BNS)

re		: fclean all

test	:
	make all
	valgrind ./push_swap "`shuf -i 1-100000 -n 500 | tr "\n" " "`"

supertest	:
	make all
	funcheck -a ./push_swap "`shuf -i -2147483648-2147483647 -n 30 | tr "\n" " "`"

run		:
	make all
	./push_swap "`shuf -i 1-100000 -n 500 | tr "\n" " "`"

.PHONY	: all clean fclean re bonus