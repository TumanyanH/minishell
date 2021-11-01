NAME = minishell

LFT_NAME = libft
LFT_PATH = ./includes/libft
LFT_FLAGS = -L$(LFT_PATH) -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror -lreadline
RM = rm -rf

FILES = ${shell find "./source/" -name "*.c"}
OBJS = ${FILES:.c=.o}

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(LFT_FLAGS) $(OBJS) -o $(NAME)
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


GM = message
push : 
	$(MAKE) fclean
	git add .
	git commit -m $(GM)
	git push 