# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/28 20:35:07 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	minirt

SRCS	=	main.c \
			mlx_utils.c \
			mini_rt.c	\
			vector/ray.c \
			vector/vector_operator.c \
			vector/vector_utility.c \
			vector/vector.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils1.c \
			color/color_utils.c \
			color/color_utils1.c \
			math/math_util.c \

SRCS_DIR = srcs
OBJS_DIR = objs

DEPS = $(OBJS:.o=.d)

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

CC		=	cc 
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g

all		: $(NAME)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${OBJS_DIR}
	@mkdir -p ${OBJS_DIR}/vector
	@mkdir -p ${OBJS_DIR}/parsing
	@mkdir -p ${OBJS_DIR}/color
	@mkdir -p $(OBJS_DIR)/math
	@${CC} ${CFLAGS}  -c $< -o $@ -MD

$(NAME): $(OBJS)
	@echo "Build ${NAME}"
	@make -C ./srcs/get_next_line
	@make -C ./srcs/libft
	@make -C ./srcs/mlx
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./srcs/get_next_line/libgnl.a ./srcs/libft/libft.a libmlx.dylib
	@echo "Build ${NAME}: done"

clean	:
	@echo "clean objects"
	@make -C ./srcs/get_next_line clean
	@make -C ./srcs/libft clean
	@make -C ./srcs/mlx clean
	@rm -rf ${OBJS_DIR}

fclean	: clean
	@echo "delete ${NAME}"
	@make -C ./srcs/get_next_line fclean
	@make -C ./srcs/libft fclean
	@make -C ./srcs/mlx clean
	@rm -rf	$(NAME)

re		:
	@make fclean
	@make all

-include $(DEPS)

.PHONY	: all clean fclean re
