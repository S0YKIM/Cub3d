/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:54:19 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 16:58:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_map_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return (i);
}

static void	read_map(int fd, t_map *map)
{
	int		ret;
	char	*line;
	char	*raw;
	int		tmp;
	
	ret = get_next_line(fd, &line);
	while (ret)
	{
		if (ret == FT_ERROR)
			exit_with_fd_close("Cannot read the next line.", line, fd);
		raw = ft_strjoin_free(raw, line, 'B');
		raw = ft_strjoin_free(raw, "\n", 'L');
		map->height++;
		tmp = ft_strlen(raw);
		if (tmp > map->width)
			map->width = tmp;
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (map->height == 0)
		exit_with_err_msg("Empty map.", NULL);
	map->map = ft_split(raw, '\n');
	free(raw);
	if (count_map_lines(map) != map->height)
		exit_with_err_msg("Wrong map.", map->map);
}

static void	check_map_contents(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		if ((map->map[i][j] != 'E') && (map->map[i][j] != 'W') && (map->map[i][j] != 'S') && (map->map[i][j] != 'N') && (map->map[i][j] != '0') && ((map->map[i][j] != '1')))
			exit_with_err_msg("Invalid map contents.", map->map);
		if ((map->map[i][j] == 'E') || (map->map[i][j] == 'W') || (map->map[i][j] == 'S') || (map->map[i][j] == 'N'))
		{
			map->player.x = j;
			map->player.y = i;
			map->num_of_player++;
		}
	}
	if (map->num_of_player != 1)
		exit_with_err_msg("Invalid number of player.", map->map);
}

void	check_map_validation(int fd, t_map *map)
{
	read_map(fd, map);
	check_map_contents(map);
	// check_wall(map);
}
