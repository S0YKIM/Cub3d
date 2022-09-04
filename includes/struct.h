/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:35 by sokim             #+#    #+#             */
/*   Updated: 2022/09/04 15:04:34 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double		x;
	double		y;
}	t_vector;

typedef struct s_key
{
	int			wasd[4];
	double		arrow;
}	t_key;

typedef struct s_player
{
	char		direction;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_key		key;
}	t_player;

typedef struct s_map
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
}	t_map;

typedef struct s_info
{
	int			fd;
	void		*mlx;
	void		*window;
	t_map		*map;
	t_player	*player;
}	t_info;

#endif
