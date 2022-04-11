NAME = minishell

LFT_NAME = libft
LFT_PATH = ./includes/libft
INCS = -Iincludes -I$(LFT_PATH)
LFT_FLAGS = -L$(LFT_PATH) -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror $(INCS) -L /Users/htumanya/lib -lreadline
#FLAGS = -Wall -Wextra -Werror $(INCS) -lreadline
RM = rm -rf

FILES = ${shell find "./source/" -name "*.c"}
OBJS = ${FILES:.c=.o}


$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(LFT_FLAGS) $(OBJS) -I /Users/htumanya/include -o $(NAME)
	@echo "Built MINISHELL"

all : $(LFT_NAME) $(NAME)

$(LFT_NAME) :
	@cd $(LFT_PATH) && $(MAKE) re
	@echo "Built LIBFT"

clean : 
	${RM} $(OBJS)

fclean : $(MAKE) clean
	${RM} ./$(NAME)

re : fclean all

M = message
push : 
	$(MAKE) fclean
	git add .
	git commit -m "$(M)"
	git push 
