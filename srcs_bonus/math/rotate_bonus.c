/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:03:24 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 12:09:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calc_rotated_vector(t_vector *vector, int angle)
{
	t_vector	tmp;

	if (!angle)
		return ;
	tmp.x = vector->x;
	tmp.y = vector->y;
	vector->x = tmp.x * cos(angle * M_PI / 180) - tmp.y * sin(angle * M_PI / 180);
	vector->y = tmp.x * sin(angle * M_PI / 180) + tmp.y * cos(angle * M_PI / 180);
}

void	rotate_vector(t_player *player, int angle)
{
	calc_rotated_vector(&player->dir, angle);
	calc_rotated_vector(&player->plane, angle);
}

void	rotate_player(t_player *player, char direction)
{
	if (direction == 'E')
		rotate_vector(player, 90);
	else if (direction == 'S')
		rotate_vector(player, 180);
	else if (direction == 'W')
		rotate_vector(player, 270);
}
