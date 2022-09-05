# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 11:32:01 by sokim             #+#    #+#              #
#    Updated: 2022/09/05 16:26:48 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
		srcs/init/info.c \
		srcs/exit/mlx.c \
		srcs/exit/program.c \
		srcs/map/map.c \
		srcs/map/check.c \
		srcs/map/wall.c \
		srcs/map/identifier.c \
		srcs/mlx/keyhook.c \
		srcs/math/rotate.c \
		srcs/map/player.c \
		srcs/mlx/draw.c \
		srcs/dda/set.c \
		srcs/dda/hit.c \
		srcs/dda/perp.c \
		srcs/dda/line.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

GNL = gnl
SRCS_GNL = libs/gnl/get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

MLX = mlx
MLX_FLAGS = -L libs/mlx -lmlx -framework OpenGL -framework Appkit

INC_FLAGS = -I includes -I libs/$(LIBFT) -I libs/$(GNL) -I libs/$(MLX)

ifdef WITH_BONUS
	SRCS_CUB = $(SRCS_B)
	OBJS_CUB = $(OBJS_B)
else
	SRCS_CUB = $(SRCS)
	OBJS_CUB = $(OBJS)
endif

ifdef WITH_BONUS
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
else
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
endif

all : $(LIBFT) $(MLX) $(NAME)
	$(info <MAKE> all$)

$(LIBFT) :
	@make --silent --directory=libs/$(LIBFT)
	$(info $<MAKE>	Libft - make$)

$(MLX) :
	@make --silent --directory=libs/$(MLX)
	$(info $<MAKE>	MinilibX - make$)

$(NAME) : $(OBJS_CUB) $(OBJS_GNL)
	$(info $<MAKE> NAME$)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CUB) $(OBJS_GNL) $(LIBFT_FLAGS) $(MLX_FLAGS)

bonus : 
	make WITH_BONUS=1 all

clean :
	@make clean --directory=libs/$(LIBFT)
	@make clean --directory=libs/$(MLX)
	rm -rf $(OBJS) $(OBJS_B) $(OBJS_GNL)

fclean : clean
	@make fclean --directory=libs/$(LIBFT)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re bonus
