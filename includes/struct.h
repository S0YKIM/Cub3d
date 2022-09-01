/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:35 by sokim             #+#    #+#             */
/*   Updated: 2022/09/01 14:47:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_map		*map;
	t_position	*player;
}				t_info;
