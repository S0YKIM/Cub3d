/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:29:13 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 13:29:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	find_tex_num(t_dda *dda)
{
	if (dda->hit_side == HIT_X)
	{
		if (dda->ray_dir_x < 0)
			return (FT_EAST);
		else
			return (FT_WEST);
	}
	else
	{
		if (dda->ray_dir_y < 0)
			return (FT_SOUTH);
		else
			return (FT_NORTH);
	}
}

void	calc_texture_offset(t_info *info, t_dda *dda, t_texture *tex)
{
	int		line_height;
	double	wall_x;

	line_height = calc_line_height(&tex->start, &tex->end, dda);
	if (dda->hit_side == HIT_X)
		wall_x = info->player->pos.y + dda->perp_wall_dist * dda->ray_dir_y;
	else
		wall_x = info->player->pos.x + dda->perp_wall_dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex->x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (dda->hit_side == HIT_X && dda->ray_dir_x > 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
	else if (dda->hit_side == HIT_Y && dda->ray_dir_y < 0)
		tex->x = TEXTURE_WIDTH - tex->x - 1;
	tex->step = 1.0 * TEXTURE_HEIGHT / line_height;
	tex->pos = (tex->start - WINDOW_HEIGHT / 2 + line_height / 2) * tex->step;
}
