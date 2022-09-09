/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:08 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 12:17:05 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_square(t_img *img, int x, int y, int color)
{
	int i;
	int j;
	int size;
	j = 0;
	size = 8;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			*(unsigned int *)(img->data + (size * x + j) * img->line_length \
				+ (size * y + i) * (img->bpp / 8)) = color;
				i++;
		}
		j++;
	}
}

static void	draw_minimap(t_info *info)
{
	int	x;
	int	y;
	int	color;
	x = 0;
	while (x < info->map->height)
	{
		y = 0;
		while (y < info->map->width)
		{
			if (ft_strchr(" 1", info->map->map[x][y]))
				color = 0;
			else if (y == (int)info->player->pos.x \
				&& x == (int)info->player->pos.y)
				color = 16711680;
			else
				color = 16777215;
			draw_square(info->img, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_line(t_info *info, t_dda *dda, int w)
{
	int			start;
	int			end;
	t_texture	tex;
	t_img		*src;
	t_img		*dst;

	calc_texture_offset(info, dda, &tex, &start, &end);
	tex.num = find_tex_num(dda);
	dst = info->img;
	src = &info->map->textures[tex.num];
	while (start < end)
	{
		tex.y = (int)tex.pos & (TEXTURE_HEIGHT - 1);
		tex.pos += tex.step;
		tex.color = *(unsigned int *)(src->data + tex.y * src->line_length + tex.x * src->bpp / 8);
		if (dda->hit_side == HIT_Y)
			tex.color = (tex.color >> 1) & 8355711;
		*(unsigned int *)(dst->data + start * dst->line_length + w * dst->bpp / 8) \
			= tex.color;
		start++;
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
				*(unsigned int *)(img->data + y * img->line_length + x * byte) = map->ceiling;
			else
				*(unsigned int *)(img->data + y * img->line_length + x * byte) = map->floor;				
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
	draw_minimap(info);
	mlx_put_image_to_window(info->mlx, info->window, info->img->img, 0, 0);
	return (0);
}
