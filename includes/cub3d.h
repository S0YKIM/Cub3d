/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:41:26 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 16:23:46 by sokim            ###   ########.fr       */
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
	char	direction;
}				t_position;

typedef struct	s_map
{
	int			height;
	int			width;
	char		**map;
	char		*tmp;
	char		**tex_files;
	int			floor;
	int			ceiling;
	int			num_of_player;
	int			start;
	int			end;
	int			flag;
}				t_map;

typedef struct	s_info
{
	int			fd;
	t_map		map;
	t_position	player;
}				t_info;

/*
 * Init functions
 */
void	init_info(t_info *info);

/*
 * Check functions
 */
void	check_map_validation(t_info *info);
int		check_map_contents(t_info *info, char *line);
void	check_wall(t_info *info);

/*
 * Identifier functions
 */
int	save_wall_texture(t_info *info, char *line);
int	save_floor_ceiling_color(t_info *info, char *line);

/*
 * Exit functions
 */
void	exit_with_free_all(char *msg, char *line, t_info *info);

#endif
