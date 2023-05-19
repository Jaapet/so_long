# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 10:05:43 by ndesprez          #+#    #+#              #
#    Updated: 2023/05/19 14:42:00 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= gnl/get_next_line.c\
gnl/get_next_line_utils.c\
checker.c\
error.c\
main.c\
parser.c

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