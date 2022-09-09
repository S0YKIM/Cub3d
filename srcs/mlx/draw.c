/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:08 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 13:27:15 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(t_info *info, t_dda *dda, int w)
{
	t_texture	tex;
	t_img		*src;
	t_img		*dst;

	calc_texture_offset(info, dda, &tex);
	tex.num = find_tex_num(dda);
	dst = info->img;
	src = &info->map->textures[tex.num];
	while (tex.start < tex.end)
	{
		tex.y = (int)tex.pos & (TEXTURE_HEIGHT - 1);
		tex.pos += tex.step;
		tex.color = *(unsigned int *)(src->data + \
			tex.y * src->line_length + tex.x * src->bpp / 8);
		if (dda->hit_side == HIT_Y)
			tex.color = (tex.color >> 1) & 8355711;
		*(unsigned int *)(dst->data + tex.start * dst->line_length + \
			w * dst->bpp / 8) = tex.color;
		tex.start++;
	}
}

static void	draw_wall(t_info *info)
{
	t_dda	dda;
	int		w;

	w = 0;
	while (w < WINDOW_WIDTH)
	{
		set_dda(&dda, info->player, w);
		find_wall_hit(&dda, info);
		set_perp_wall_dist(&dda, info->player);
		draw_line(info, &dda, w);
		w++;
	}
}

static void	draw_ceiling_floor(t_img *img, t_map *map)
{
	int	x;
	int	y;
	int	byte;

	byte = img->bpp / 8;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y < WINDOW_HEIGHT / 2)
				*(unsigned int *)(img->data + y * \
					img->line_length + x * byte) = map->ceiling;
			else
				*(unsigned int *)(img->data + y * \
					img->line_length + x * byte) = map->floor;
			y++;
		}
		x++;
	}
}

int	draw_frame(t_info *info)
{
	set_player_position(info);
	draw_ceiling_floor(info->img, info->map);
	draw_wall(info);
	mlx_put_image_to_window(info->mlx, info->window, info->img->img, 0, 0);
	return (0);
}
