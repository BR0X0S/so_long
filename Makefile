# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:21:31 by oumondad          #+#    #+#              #
#    Updated: 2024/02/19 17:13:07 by oumondad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = check_map_final.c check_map_utils.c destroy_all.c drawing_map.c flood_fill.c ft_split.c \
	get_next_line_utils.c get_next_line.c mini_lbft.c mouve_count.c moving.c so_long.c

OBJ = ${SRC:.c=.o}

BSRC = check_map_final_bonus.c check_map_utils_bonus.c destroy_all_bonus.c drawing_map_bonus.c flood_fill_bonus.c \
	ft_split.c get_next_line_utils.c get_next_line.c mini_lbft.c mouve_count_bonus.c moving_bonus.c so_long_bonus.c \
	ft_itoa.c

BOBJ = ${BSRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus : ${BOBJ}
	${CC} ${CFLAGS} ${BOBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean :
	rm -rf ${OBJ} ${BOBJ}

fclean : clean
	rm -f ${NAME} ${bonus}

re : fclean all

.PHONY : all clean fclean re bonus

.SECONDARY : ${OBJ}