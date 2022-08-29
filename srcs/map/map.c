/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:54:19 by sokim             #+#    #+#             */
/*   Updated: 2022/08/29 13:11:13 by sokim            ###   ########.fr       */
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

static void	save_wall_texture(t_map *map, char *line)
{
	if (!ft_strncmp(line, "EA ", 3))
		map->tex_files[FT_EAST] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		map->tex_files[FT_WEST] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		map->tex_files[FT_SOUTH] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "NO ", 3))
		map->tex_files[FT_NORTH] = ft_strdup(line + 3);
}

static void	change_into_rgb_color(t_map *map, char *line)
{
	(void) map;
	if (!ft_strncmp(line, "F ", 2))
		;
	else if (!ft_strncmp(line, "C ", 2))
		;
}

static void	check_floor_ceiling_color(t_info *info, char *line)
{
	int	color[3];
	int	i;
	int	cnt;

	i = 2;
	cnt = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		color[cnt] = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] && line[i] != ',')
		exit_with_free_all("Invalid color type.", line, info);
	change_into_rgb_color(&info->map, line);
}

static void	check_map_contents(t_info *info, char *line)
{
	if (line[0] == '\n')
		return ;
	if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3))
		save_wall_texture(&info->map, line);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		check_floor_ceiling_color(info, line);
	if (!ft_strchr(" EWSN01", line[0]))
		exit_with_free_all("Invalid map contents.", line, info);

}

static void	read_map(t_info *info)
{
	int		ret;
	char	*line;
	char	*raw;
	int		tmp;
	
	ret = get_next_line(info->fd, &line);
	while (ret)
	{
		if (ret == FT_ERROR)
			exit_with_free_all("Cannot read the next line.", line, info);
		raw = ft_strjoin_free(raw, line, 'B');
		raw = ft_strjoin_free(raw, "\n", 'L');
		info->map.height++;
		tmp = ft_strlen(line);
		if (tmp > info->map.width)
			info->map.width = tmp;
		check_map_contents(info, line);
		ret = get_next_line(info->fd, &line);
	}
	free(line);
	if (info->map.height == 0)
		exit_with_free_all("Empty map.", NULL, info);
	info->map.map = ft_split(raw, '\n');
	free(raw);
	if (count_map_lines(&info->map) != info->map.height)
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
		while (j < info->map.width)
		{
			if (ft_strchr("EWSN", info->map.map[i][j]))
			{
				info->player.x = j;
				info->player.y = i;
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
	// check_wall(map);
	get_player_position(info);
}
