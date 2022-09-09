/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:22 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 12:08:18 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	find_wall_hit(t_dda *dda, t_info *info)
{
	while (!dda->is_hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->hit_side = HIT_X;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->hit_side = HIT_Y;
		}
		if (dda->map_x < 0 || dda->map_x >= info->map->width
			|| dda->map_y < 0 || dda->map_y >= info->map->height)
			return ;
		else if (info->map->map[dda->map_y][dda->map_x] == '1')
			dda->is_hit = FT_TRUE;
	}
}
