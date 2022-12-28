# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/28 10:15:11 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

					  
SRCS				= ft_atoi.c \
					  ft_atof.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_itoa.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_putchar_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c \
					  ft_putstr_fd.c \
					  ft_split.c \
					  ft_strchr.c \
					  ft_strdup.c \
					  ft_strjoin.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c \
					  ft_strmapi.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_strrchr.c \
					  ft_strtrim.c \
					  ft_substr.c \
					  ft_tolower.c \
					  ft_toupper.c \
					  ft_striteri.c \
					  ft_strcmp.c \
					  ft_strs_size.c \
					  ft_print_exit.c \
					  ft_release_strs.c \

BNS_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJS = $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

ifdef BONUS
	OBJS += $(BNS_OBJS)
endif

FLAGS = -Wall -Wextra -Werror -g

CC = cc

NAME = libft.a

all	: $(NAME)

%.o	:%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I libft.h

$(NAME)	: $(OBJS)
	@ar -rc $(NAME) $(OBJS)

bonus :
	make BONUS=1 all

clean	:
	@rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
	@rm -f $(NAME)

re	:	
	@make fclean
	@make all

.PHONY	:	all clean fclean re
