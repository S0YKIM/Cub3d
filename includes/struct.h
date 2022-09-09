/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:35 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 13:25:26 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_vector
{
	double		x;
	double		y;
}	t_vector;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_texture
{
	int			x;
	int			y;
	double		step;
	double		pos;
	int			num;
	uint32_t	color;
	int			start;
	int			end;
}	t_texture;

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

typedef struct s_img
{
	void	*img;
	char	*data;
	int		line_length;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	int			height;
	int			width;
	char		**map;
	char		*tmp;
	char		**tex_files;
	t_img		textures[4];
	int			floor;
	int			ceiling;
	int			num_of_player;
	int			start;
	int			end;
	int			flag;
}	t_map;

typedef struct s_dda
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	bool	is_hit;
	int		hit_side;
	double	perp_wall_dist;
}	t_dda;

typedef struct s_info
{
	int			fd;
	void		*mlx;
	void		*window;
	t_map		*map;
	t_player	*player;
	t_img		*img;
}	t_info;

#endif
