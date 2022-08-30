/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:29:04 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 16:35:45 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_space_or_garbage(t_info *info, int i, int j)
{
	if (info->map.map[i][j] == '0' || \
		info->map.map[i][j] == info->player.direction)
	{
		if (!info->map.map[i - 1][j] || info->map.map[i - 1][j] == ' ')
			exit_with_free_all("Map is not surrounded by wall.", NULL, info);
		if (!info->map.map[i + 1][j] || info->map.map[i + 1][j] == ' ')
			exit_with_free_all("Map is not surrounded by wall.", NULL, info);
		if (!info->map.map[i][j - 1] || info->map.map[i][j - 1] == ' ')
			exit_with_free_all("Map is not surrounded by wall.", NULL, info);
		if (!info->map.map[i][j + 1] || info->map.map[i][j + 1] == ' ')
			exit_with_free_all("Map is not surrounded by wall.", NULL, info);
	}
}

static void	check_boundary(t_info *info, int i, int j)
{
	if (info->map.map[i][j] == '0' || \
		info->map.map[i][j] == info->player.direction)
		exit_with_free_all("Map is not surrounded by wall.", NULL, info);
}	

void	check_wall(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map.map[i])
	{
		j = 0;
		while (info->map.map[i][j])
		{
			if (i == 0 || i == info->map.height - 1 || \
				j == 0 || j == info->map.width)
				check_boundary(info, i, j);
			else
				check_space_or_garbage(info, i, j);
			j++;
		}
		i++;
	}
}
