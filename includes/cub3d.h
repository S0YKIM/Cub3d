/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:41:26 by sokim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/28 16:52:19 by sokim            ###   ########.fr       */
=======
/*   Updated: 2022/08/28 16:20:07 by sokim            ###   ########.fr       */
>>>>>>> e14c61ee6d0038a0e05c227744b334c8252e7175
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
	int			num_of_player;
	int			start;
	int			end;
	t_position	player;
}				t_map;

/*
 * Init functions
 */
void	init_map(t_map *map);

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
