/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:59:45 by sokim             #+#    #+#             */
/*   Updated: 2022/09/06 11:58:02 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_edge(char **map, t_player *player, t_vector *next)
{
	int			x;
	int			y;

	x = (int)next->x;
	y = (int)next->y;
	if (player->dir.x < 0 && player->dir.y < 0)
		return (map[y + 1][x] == '1' && map[y][x + 1] == '1');
	else if (player->dir.x > 0 && player->dir.y < 0)
		return (map[y + 1][x] == '1' && map[y][x - 1] == '1');
	else if (player->dir.x < 0 && player->dir.y > 0)
		return (map[y - 1][x] == '1' && map[y][x + 1] == '1');
	else if (player->dir.x > 0 && player->dir.y > 0)
		return (map[y - 1][x] == '1' && map[y][x - 1] == '1');
	return (FT_FALSE);
}

static bool	is_available_to_move(t_map *map, t_player *player, t_vector *next)
{
	if (next->x < 0 || next->x >= map->width)
		return (FT_FALSE);
	if (next->y < 0 || next->y >= map->height)
		return (FT_FALSE);
	if (map->map[(int)next->y][(int)next->x] == '1')
		return (FT_FALSE);
	if (is_edge(map->map, player, next))
		return (FT_FALSE);
	return (FT_TRUE);
}

static void	move_player(t_info *info, t_vector *delta)
{
	t_vector	next;

	if (!delta->x && !delta->y)
		return ;
	next.x = info->player->pos.x + delta->x;
	next.y = info->player->pos.y + delta->y;
	if (is_available_to_move(info->map, info->player, &next))
	{
		info->player->pos.x = next.x;
		info->player->pos.y = next.y;
	}
}

static void	get_amount_to_move(t_info *info, t_vector *delta)
{
	if (info->player->key.wasd[FT_EAST])
	{
		delta->x += info->player->plane.x * PLAYER_MOVE_SPEED;
		delta->y += info->player->plane.y * PLAYER_MOVE_SPEED;
	}
	if (info->player->key.wasd[FT_WEST])
	{
		delta->x += info->player->plane.x * PLAYER_MOVE_SPEED * -1;
		delta->y += info->player->plane.y * PLAYER_MOVE_SPEED * -1;
	}
	if (info->player->key.wasd[FT_NORTH])
	{
		delta->x += info->player->dir.x * PLAYER_MOVE_SPEED;
		delta->y += info->player->dir.y * PLAYER_MOVE_SPEED;
	}
	if (info->player->key.wasd[FT_SOUTH])
	{
		delta->x += info->player->dir.x * PLAYER_MOVE_SPEED * -1;
		delta->y += info->player->dir.y * PLAYER_MOVE_SPEED * -1;
	}
}

void	set_player_position(t_info *info)
{
	t_vector	delta;

	delta.x = 0;
	delta.y = 0;
	get_amount_to_move(info, &delta);
	move_player(info, &delta);
	rotate_vector(info->player, info->player->key.arrow);
}
