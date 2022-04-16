# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 20:20:25 by htumanya          #+#    #+#              #
#    Updated: 2022/04/16 20:23:11 by htumanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(shell find "." -name "*.c")
BONUSES 	= $(shell find "." -name "ft_lst*.c")
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS 	= ${BONUSES:.c=.o}
NAME		= libft.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${AR} libft.a ${OBJS}

bonus : ${BONUS_OBJS}
	${AR} libft.a ${BONUS_OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all bonus

.PHONY: all clean fclean bonus re .c.o
