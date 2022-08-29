/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:16:58 by sokim             #+#    #+#             */
/*   Updated: 2022/08/29 11:50:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->tex_files = (char **)ft_calloc(4, sizeof(char *));
	if (!map->tex_files)
		exit_with_free_all("Memory allocation failed.", NULL, NULL, 0);
	map->floor = -1;
	map->ceiling = -1;
	map->num_of_player = 0;
}
