/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:22 by sokim             #+#    #+#             */
/*   Updated: 2022/09/05 14:37:33 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_edge(char **map, t_dda *dda, int x, int y)
{
	if (dda->ray_dir_x < 0 && dda->ray_dir_y < 0)
		return (map[y + 1][x] == '1' && map[y][x + 1] == '1');
	else if (dda->ray_dir_x > 0 && dda->ray_dir_y < 0)
		return (map[y + 1][x] == '1' && map[y][x - 1] == '1');
	else if (dda->ray_dir_x < 0 && dda->ray_dir_y > 0)
		return (map[y - 1][x] == '1' && map[y][x + 1] == '1');
	else if (dda->ray_dir_x > 0 && dda->ray_dir_y > 0)
		return (map[y - 1][x] == '1' && map[y][x - 1] == '1');
	return (FT_TRUE);
}

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
		if (info->map->map[dda->map_y][dda->map_x] == '1')
			dda->is_hit = FT_TRUE;
		if (is_edge(info->map->map, dda, dda->map_x, dda->map_y))
			dda->is_hit = FT_TRUE;
	}
}
