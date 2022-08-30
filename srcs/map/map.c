/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:54:19 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 15:18:24 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	read_map(t_info *info)
{
	int		ret;
	char	*line;
	
	ret = get_next_line(info->fd, &line);
	while (ret)
	{
		if (ret == FT_ERROR)
			exit_with_free_all("Cannot read the next line.", line, info);
		info->map.end++;
		check_map_contents(info, line);
		free(line);
		ret = get_next_line(info->fd, &line);
	}
	free(line);
	info->map.height = info->map.end - info->map.start + 1;
	if (info->map.height == 0)
		exit_with_free_all("Empty map.", NULL, info);
	info->map.map = ft_split(info->map.tmp, '\n');
	if (count_map_lines(info->map.map) != info->map.height)
		exit_with_free_all("Wrong map.", NULL, info);
}

static void	get_player_position(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (info->map.map[i][j])
		{
			if (ft_strchr("EWSN", info->map.map[i][j]))
			{
				info->player.x = j;
				info->player.y = i;
				info->player.direction = info->map.map[i][j];
				info->map.num_of_player++;
			}
			j++;
		}
		i++;
	}
	if (info->map.num_of_player != 1)
		exit_with_free_all("Invalid number of player.", NULL, info);
}

void	check_map_validation(t_info *info)
{
	read_map(info);
	check_wall(info);
	get_player_position(info);
}
