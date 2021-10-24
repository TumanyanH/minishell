NAME = minishell
LFT_NAME = libft

CC = gcc
FLAGS = -Wall -Wextra -Werror

LFT_PATH = ./libs/libft
FILES = ./main.c
OBJS = ${FILES:.c=.o}

RM = rm -rf

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Built MINISHELL"

$(LFT_NAME) :
	@cd $(LFT_PATH) && $(MAKE) re
	@echo "Built LIBFT"

all : $(LFT_NAME) $(NAME)

clean : 
	${RM} $(OBJS)

fclean : $(MAKE) clean
	${RM} ./$(NAME)

re : fclean all
