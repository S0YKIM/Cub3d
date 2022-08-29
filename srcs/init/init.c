/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:16:58 by sokim             #+#    #+#             */
/*   Updated: 2022/08/29 15:35:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_position(t_position *player)
{
	player->x = -1;
	player->y = -1;
	player->direction = -1;
}

static void	init_map(t_info *info, t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->tex_files = (char **)ft_calloc(4, sizeof(char *));
	if (!map->tex_files)
		exit_with_free_all("Memory allocation failed.", NULL, info);
	map->floor = -1;
	map->ceiling = -1;
	map->num_of_player = 0;
	map->start = 0;
	map->end = 0;
	map->flag = 0;
}

void	init_info(t_info *info)
{
	info->fd = 0;
	init_map(info, &info->map);
	init_position(&info->player);
}
