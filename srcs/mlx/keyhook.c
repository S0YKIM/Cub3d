/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:30:59 by sokim             #+#    #+#             */
/*   Updated: 2022/09/04 13:59:05 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_position(int keycode, t_info *info, int value)
{
	if (keycode == KEY_D)
		info->player->key.wasd[FT_EAST] = value;
	else if (keycode == KEY_A)
		info->player->key.wasd[FT_WEST] = value;
	else if (keycode == KEY_S)
		info->player->key.wasd[FT_SOUTH] = value;
	else if (keycode == KEY_W)
		info->player->key.wasd[FT_NORTH] = value;
	return (FT_TRUE);
}

static int	move_direction_vector(int keycode, t_info *info)
{
	if (keycode == KEY_LEFT)
		info->player->key.arrow = -PLAYER_SPEED;
	else if (keycode == KEY_RIGHT)
		info->player->key.arrow = PLAYER_SPEED;
	return (FT_TRUE);
}

int	key_down(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_with_button_close(info);
	else if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_S || keycode == KEY_W)
		return (move_player_position(keycode, info, FT_TRUE));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (move_direction_vector(keycode, info));
	return (FT_TRUE);
}

int	key_up(int keycode, t_info *info)
{
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_S || keycode == KEY_W)
		return (move_player_position(keycode, info, FT_FALSE));
	else if (keycode == KEY_LEFT)
		info->player->key.arrow = 0;
	else if (keycode == KEY_RIGHT)
		info->player->key.arrow = 0;
	return (FT_TRUE);
}
