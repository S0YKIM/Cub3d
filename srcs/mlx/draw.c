/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:08 by sokim             #+#    #+#             */
/*   Updated: 2022/09/05 15:51:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->window, x, y, color);
		y++;
	}
}

static void	draw_line(t_info *info, t_dda *dda, int w)
{
	int	start;
	int	end;
	int	color;

	calc_line_height(&start, &end, dda);
	color = 13145800;
	verLine(info, w, start, end, color);
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

void	draw_frame(t_info *info)
{
	set_player_position(info);
	draw_ceiling_floor(info->img, info->map);
	// draw_wall(info);
	mlx_put_image_to_window(info->mlx, info->window, info->img->img, 0, 0);
}
