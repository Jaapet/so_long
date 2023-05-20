# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 10:05:43 by ndesprez          #+#    #+#              #
#    Updated: 2023/05/20 18:15:21 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= gnl/get_next_line.c\
gnl/get_next_line_utils.c\
checking/checker.c\
checking/path_checker.c\
parsing/error.c\
parsing/builder.c\
parsing/parser.c\
parsing/utils.c\
mlx/mlx.c\
mlx/mlx_utils.c\
mlx/event_listener.c\
mlx/moves.c\
main.c

NAME = so_long

OBJECTS	= ${SOURCES:.c=.o}

FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

${NAME} : ${OBJECTS}
		gcc $(FLAGS) $(MLX_FLAGS) $(OBJECTS) -o $(NAME)

all : ${NAME}

clean :
		rm -f ${OBJECTS}

fclean : clean
		rm -f ${NAME}

re : fclean all