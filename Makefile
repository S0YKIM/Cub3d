# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 11:32:01 by sokim             #+#    #+#              #
#    Updated: 2022/09/11 17:18:18 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main \
		init/info \
		exit/mlx \
		exit/program \
		map/map \
		map/check \
		map/wall \
		map/identifier \
		mlx/keyhook \
		math/rotate \
		map/player \
		mlx/draw \
		dda/set \
		dda/hit \
		dda/perp \
		dda/line \
		init/texture \
		mlx/texture

FILES_BONUS_ONLY = mlx/minimap

SRCS_DIR = ./srcs/
SRCS_B_DIR = ./srcs_bonus/

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_B_DIR), $(addsuffix _bonus.c, $(FILES))) \
		$(addprefix $(SRCS_B_DIR), $(addsuffix _bonus.c, $(FILES_BONUS_ONLY)))

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
