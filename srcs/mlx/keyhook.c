/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:30:59 by sokim             #+#    #+#             */
/*   Updated: 2022/09/02 15:39:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_position(int keycode, t_info *info)
{
	(void) keycode;
	(void) info;
	return (1);
}

int	key_down(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_with_button_close(info);
	else if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_S || keycode == KEY_W)
		return (move_player_position(keycode, info));
	return (1);
}

int	key_up(int keycode, t_info *info)
{
	(void) keycode;
	(void) info;
	return (1);
}
