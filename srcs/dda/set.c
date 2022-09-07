/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:46:13 by sokim             #+#    #+#             */
/*   Updated: 2022/09/07 12:31:12 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dda(t_dda *dda, t_player *player, double w)
{
	dda->camera_x = 2 * w / (float) WINDOW_WIDTH - 1;
	dda->ray_dir_x = player->dir.x + player->plane.x * dda->camera_x;
	dda->ray_dir_y = player->dir.y + player->plane.y * dda->camera_x;
	dda->map_x = (int)player->pos.x;
	dda->map_y = (int)player->pos.y;
	dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	dda->step_x = 1;
	dda->step_y = 1;
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (player->pos.x - dda->map_x) * dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1 - player->pos.x) * dda->delta_dist_x;
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (player->pos.y - dda->map_y) * dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1 - player->pos.y) * dda->delta_dist_y;
	dda->is_hit = FT_FALSE;
}
