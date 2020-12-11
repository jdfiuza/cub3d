# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 10:35:52 by jheras-f          #+#    #+#              #
#    Updated: 2020/01/31 08:02:04 by jheras-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH	= objs/

SRCS		= ./srcs/
LIBFT		= ./libft/
GNL			= ./gnl/

SRC			= $(SRCS)main.c $(SRCS)read_map.c $(SRCS)map_utils.c \
			  $(SRCS)cub3d.c $(SRCS)events.c $(SRCS)put_scenario.c \
			  $(SRCS)raycast.c $(SRCS)load_images.c $(SRCS)miscellaneous.c \
			  $(SRCS)sprites.c $(SRCS)bpm_to_file.c $(SRCS)validate_map.c \
			  $(SRCS)event_listener.c $(SRCS)validate_conf.c \
			  $(SRCS)finish.c $(SRCS)main_check.c $(SRCS)raycast_aux.c \
			  $(SRCS)sprite_draw.c $(SRCS)sprite_property.c \
			  $(LIBFT)ft_atoi.c $(LIBFT)ft_strlen.c $(LIBFT)ft_split.c \
			  $(LIBFT)ft_substr.c $(LIBFT)ft_strcmp.c $(LIBFT)ft_strdup.c \
			  $(LIBFT)ft_memcpy.c $(LIBFT)ft_isnum.c \
			  $(GNL)get_next_line.c $(GNL)get_next_line_utils.c

BSRC		= $(SRCS)main_bonus.c $(SRCS)read_map.c $(SRCS)map_utils.c \
			  $(SRCS)cub3d_bonus.c $(SRCS)events.c $(SRCS)put_scenario_bonus.c \
			  $(SRCS)raycast_bonus.c $(SRCS)load_images_bonus.c \
			  $(SRCS)miscellaneous.c $(SRCS)raycast_aux_bonus.c \
			  $(SRCS)sprites.c $(SRCS)bpm_to_file.c \
			  $(SRCS)validate_map_bonus.c $(SRCS)game_extra_bonus.c \
			  $(SRCS)event_listener_bonus.c $(SRCS)validate_conf.c \
			  $(SRCS)finish_bonus.c $(SRCS)main_check.c  \
			  $(SRCS)sprite_draw_bonus.c $(SRCS)sprite_property.c \
			  $(SRCS)game_bonus.c \
			  $(LIBFT)ft_atoi.c $(LIBFT)ft_strlen.c $(LIBFT)ft_split.c \
			  $(LIBFT)ft_substr.c $(LIBFT)ft_strcmp.c $(LIBFT)ft_strdup.c \
			  $(LIBFT)ft_memcpy.c $(LIBFT)ft_isnum.c $(LIBFT)ft_itoa.c \
			  $(GNL)get_next_line.c $(GNL)get_next_line_utils.c


OBJS		= $(SRC:.c=.o)
BOBJS		= $(BSRC:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lminilibx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= cub3D
BNAME			= cub3D_bonus

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				$(CC) ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(BNAME):		$(MLX) $(BOBJS)
				$(CC) ${CFLAGS} -o ${BNAME} ${BOBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C minilibx
				@mv minilibx/$(MLX) ./lib

bonus:			$(MLX) $(BOBJS)
				$(CC) ${CFLAGS} -o ${BNAME} ${BOBJS} ${LIBS}

clean:
				@$(MAKE) -C minilibx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX) $(BNAME) $(BOBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
