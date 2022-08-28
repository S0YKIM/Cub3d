/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:41:26 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 15:57:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define FT_FALSE 0
# define FT_TRUE 1
# define FT_ERROR -1

# define FT_EAST 0
# define FT_WEST 1
# define FT_SOUTH 2
# define FT_NORTH 3

typedef struct	s_position
{
	int		x;
	int		y;
	int		direction;
}				t_position;

typedef struct	s_map
{
	int			height;
	int			width;
	char		**map;
	t_position	player;
	int			num_of_player;
}				t_map;

/*
 * Check functions
 */
void	check_map_validation(int fd, t_map *map);

/*
 * Exit functions
 */
void	exit_with_err_msg(char *msg, char **map);
void	exit_with_fd_close(char *msg, char *line, int fd);

#endif
