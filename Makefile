# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2023/03/02 14:21:52 by hyunkyle         ###   ########.fr        #
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
			Matrix/debug_mat.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils1.c \
			parsing/parsing_utils2.c \
			parsing/parsing_bonus.c \
			parsing/parsing_bonus1.c \
			parsing/parsing_bonus_utils.c \
			render/put_img.c \
			render/render.c \
			render/shade.c \
			render/shade2.c \
			render/shade3.c \
			render/shade4.c \
			render/shade5.c \
			settings/setting.c \
			vector/ray.c \
			vector/vector_operator.c \
			vector/vector_utility.c \
			vector/vector.c \
			vector/clamp.c \
			parsing_ppm/argv.c \
			parsing_ppm/parsing_ppm.c \
			parsing_ppm/parse_ppm.c \
			
SRCS_DIR = srcs
OBJS_DIR = objs

DEPS = $(OBJS:.o=.d)

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

CC		=	cc 
Debug = -fsanitize=address -g
CFLAGS	=	-Wall -Werror -Wextra -Imlx -O3
LFAGS = -framework OpenGL -framework AppKit
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
	@mkdir -p ${OBJS_DIR}/parsing_ppm
	@${CC} ${CFLAGS} -c $< -o $@ -MD

$(NAME): $(OBJS)
	@echo "Build ${NAME}"
	@make -C ./srcs/get_next_line
	@make -C ./srcs/libft
	@make -C ./srcs/mlx
	@$(CC) $(OBJS) -o $(NAME) ./srcs/get_next_line/libgnl.a ./srcs/libft/libft.a libmlx.dylib $(LFAGS)
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
