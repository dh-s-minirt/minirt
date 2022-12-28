# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/28 10:15:43 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 			get_next_line_bonus.c \
				get_next_line_utils_bonus.c  \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libgnl.a

all	: $(NAME)
	
.c.o :
	@$(CC) $(FLAGS) -o $@ -c $< -I .

$(NAME)	: $(OBJS)
	@ar -rc $(NAME) $(OBJS)

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re	:	
	@make fclean 
	@make all

.PHONY	:	all clean fclean re
