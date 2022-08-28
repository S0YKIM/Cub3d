/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:16:58 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 16:19:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->player.x = -1;
	map->player.y = -1;
	map->player.direction = -1;
	map->num_of_player = 0;
}
