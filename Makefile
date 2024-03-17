NAME = push_swap
BNAME = checker
CC = cc

SRC = 	stack.c \
		parse.c \
		main.c	\
		instructions.c \

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME):$(OBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(SRC) -Wall -Wextra -Werror -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a -o $(NAME)

$(BNAME):$(BOBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(SRC) -Wall -Wextra -Werror -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a -o $(BNAME)


clean:
	rm -rf $(OBJ) $(BOBJ)
	@make clean -C libft
	@make clean -C ft_printf
fclean: clean
	rm -rf $(NAME) $(BNAME)
	@make fclean -C libft
	@make fclean -C ft_printf
re: fclean all
