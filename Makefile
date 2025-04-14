NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror 

SRC = ft_split.c ft_atoi.c push_sawp.c check_input.c creat_stack.c push.c rev_rotate.c rotate.c  \
		stack_size.c swap.c ft_sort_3.c check_sort.c radix_sort.c  sort_20.c utils.c

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c 
	@$(CC) $(FLAGS) -c $< -o $@ 

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f  $(NAME)

re : fclean all 

.PHONY : all clean fclean re 
