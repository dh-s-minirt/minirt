# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2023/02/14 00:00:05 by daegulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	minirt

SRCS	=	main.c \
			mlx_utils.c \
			mini_rt.c	\
			color/color_utils.c \
			color/color_utils1.c \
			color/color_utils2.c \
			hit_record/hit_intersect1.c \
			hit_record/hit_intersect2.c \
			hit_record/hit_intersect3.c \
			hit_record/hit_trace.c \
			math/math_util.c \
			Matrix/arr_vec.c \
			Matrix/mat_rotate.c \
			Matrix/mat_transform.c \
			Matrix/mat.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils1.c \
			render/put_img.c \
			render/render.c \
			render/shade.c \
			settings/setting.c \
			vector/ray.c \
			vector/vector_operator.c \
			vector/vector_utility.c \
			vector/vector.c \


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
	@mkdir -p ${OBJS_DIR}/hit_record
	@mkdir -p ${OBJS_DIR}/Matrix
	@mkdir -p ${OBJS_DIR}/render
	@mkdir -p ${OBJS_DIR}/settings
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
