NAME = push_swap
BNAME = checker
CC = cc

SRC = 	stack.c \
		stack1.c \
		parse.c \
		parse1.c \
		main.c	\
		instructions.c \
		instructions1.c \
		instructions2.c \
		instructions3.c \
		instructions4.c \
		instructions5.c \

BSRC = 	bonus/stack_bonus.c \
		bonus/stack1_bonus.c \
		bonus/parse_bonus.c \
		bonus/parse1_bonus.c \
		bonus/main_bonus.c	\
		bonus/instructions_bonus.c \
		bonus/instructions1_bonus.c \
		bonus/instructions2_bonus.c \
		bonus/instructions3_bonus.c \
		bonus/instructions4_bonus.c \
		bonus/instructions5_bonus.c \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME) 

$(NAME):$(OBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(SRC) -Wall -Wextra -Werror -fsanitize=address -g3  ./ft_printf/libftprintf.a ./libft/libft.a -o $(NAME)

$(BNAME):$(BOBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(BSRC) -Wall -Wextra -Werror -fsanitize=address -g3 ./ft_printf/libftprintf.a ./libft/libft.a -o $(BNAME)

bonus : $(BNAME)

clean:
	rm -rf $(OBJ) bonus/*.o
	@make clean -C libft
	@make clean -C ft_printf
fclean: clean
	rm -rf $(NAME) $(BNAME)
	@make fclean -C libft
	@make fclean -C ft_printf
re: fclean all
.SECONDARY: $(OBJ) $(BOBJ)