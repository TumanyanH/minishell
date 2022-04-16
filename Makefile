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


all : $(LFT_NAME) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -I /Users/htumanya/include/readline $(FLAGS) $(LFT_FLAGS) $(OBJS) -o $(NAME)
	@echo "Built MINISHELL"

$(LFT_NAME) :
	@cd $(LFT_PATH) && $(MAKE) all

clean : 
	@cd $(LFT_PATH) && $(MAKE) clean
	${RM} $(OBJS)

fclean : $(MAKE) clean
	@cd $(LFT_PATH) && $(MAKE) fclean
	${RM} ./$(NAME)

re : fclean all

M = message
push : 
	$(MAKE) fclean
	git add .
	git commit -m "$(M)"
	git push 
