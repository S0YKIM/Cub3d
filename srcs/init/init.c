/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:16:58 by sokim             #+#    #+#             */
/*   Updated: 2022/09/02 18:36:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player->direction = 'N';
	player->pos.x = -1;
	player->pos.y = -1;
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 0.66;
	player->plane.y = 0;
}

static void	init_map(t_info *info, t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->tmp = ft_strdup("");
	if (!map->tmp)
		exit_with_free_all("Memory allocation failed.", NULL, info);
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
	info->mlx = NULL;
	info->window = NULL;
	info->map = (t_map *)malloc(sizeof(t_map));
	if (!info->map)
		exit_with_free_all("Memory allocation failed.", NULL, info);
	info->player = (t_player *)malloc(sizeof(t_player));
	if (!info->player)
		exit_with_free_all("Memory allocation failed.", NULL, info);
	init_map(info, info->map);
	init_player(info->player);
}
