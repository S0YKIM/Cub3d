/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:37:24 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 13:36:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_square(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = 8;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			*(unsigned int *)(img->data + (size * y + j) * img->line_length \
				+ (size * x + i) * (img->bpp / 8)) = color;
				i++;
		}
		j++;
	}
}

static void	interpolate(t_info *info, int *x, int y)
{
	while (*x < info->map->width)
	{
		draw_square(info->img, *x, y, 0);
		(*x)++;
	}
}

void	set_color(t_info *info, int *color, int x, int y)
{
	if (ft_strchr(" 1", info->map->map[y][x]))
		*color = 0;
	else if (x == (int)info->player->pos.x \
		&& y == (int)info->player->pos.y)
		*color = 16711680;
	else
		*color = 16777215;
}

void	draw_minimap(t_info *info)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (!info->map->map[y][x])
			{
				interpolate(info, &x, y);
				continue ;
			}
			set_color(info, &color, x, y);
			draw_square(info->img, x, y, color);
			x++;
		}
		y++;
	}
}
