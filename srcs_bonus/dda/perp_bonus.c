/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:39:25 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 12:08:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_perp_wall_dist(t_dda *dda, t_player *player)
{
	if (dda->hit_side == HIT_X)
			dda->perp_wall_dist = (dda->map_x - player->pos.x \
			+ (1 - dda->step_x) / 2) / dda->ray_dir_x;
	else
		dda->perp_wall_dist = (dda->map_y - player->pos.y \
			+ (1 - dda->step_y) / 2) / dda->ray_dir_y;
}
