/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:54:19 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 12:01:54 by sokim            ###   ########.fr       */
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

static int	save_wall_texture(t_info *info, char *line)
{
	int	direction;

	direction = -1;
	if (!ft_strncmp(line, "EA ", 3))
		direction = FT_EAST;
	else if (!ft_strncmp(line, "WE ", 3))
		direction = FT_WEST;
	else if (!ft_strncmp(line, "SO ", 3))
		direction = FT_SOUTH;
	else if (!ft_strncmp(line, "NO ", 3))
		direction = FT_NORTH;
	if (info->map.tex_files[direction])
		exit_with_free_all("Duplicated wall texture info.", line, info);
	info->map.tex_files[direction] = ft_strdup(line + 3);
	return (FT_TRUE);
}

static int	change_into_rgb_color(t_info *info, char *line, int *color)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (info->map.floor != -1)
			exit_with_free_all("Duplicated floor color info.", line, info);
		info->map.floor = color[0] << 16 | color[1] << 8 | color[2];
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (info->map.ceiling != -1)
			exit_with_free_all("Duplicated ceiling color info.", line, info);
		info->map.ceiling = color[0] << 16 | color[1] << 8 | color[2];
	}
	return (FT_TRUE);
}

static int	check_floor_ceiling_color(t_info *info, char *line)
{
	int	color[3];
	int	i;
	int	cnt;

	i = 2;
	cnt = 0;
	while (line[i] && cnt <= 2)
	{
		while (ft_isspace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
			color[cnt] = ft_atoi(line + i);
		if (color[cnt] < 0 || color[cnt] > 255)
			exit_with_free_all("Invalid color type.", line, info);
		while (ft_isdigit(line[i]) || line[i] == '\n')
			i++;
		if (line[i] && line[i] != ',')
			exit_with_free_all("Invalid color type.", line, info);
		if (line[i] && line[i++] == ',')
			cnt++;
	}
	if (cnt != 2)
		exit_with_free_all("Invalid color type.", line, info);
	return (change_into_rgb_color(info, line, color));
}

static void	check_preconditions(t_map *map, t_info *info, char *line)
{
	int	i;

	if (info->map.flag == FT_TRUE)
		return ;
	i = 0;
	while (i < 4)
	{
		if (!map->tex_files[i])
			exit_with_free_all("Not enough texture info.", line, info);
		i++;
	}
	if (map->floor == FT_ERROR)
		exit_with_free_all("There is no floor color info.", line, info);
	if (map->ceiling == FT_ERROR)
		exit_with_free_all("There is no ceiling color info.", line, info);
	info->map.flag = FT_TRUE;
}

static int	check_map_contents(t_info *info, char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		return (FT_FALSE);
	if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3))
		return (save_wall_texture(info, line));
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (check_floor_ceiling_color(info, line));
	while (line[i])
	{
		if (!ft_strchr(" EWSN01", line[i]))
			exit_with_free_all("Invalid map contents.", line, info);
		check_preconditions(&info->map, info, line);
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (i > info->map.width)
			info->map.width = i;
		info->map.height++;
		info->map.tmp = ft_strjoin_free(info->map.tmp, line, 'L');
		info->map.tmp = ft_strjoin_free(info->map.tmp, "\n", 'L');
	}
	return (FT_TRUE);
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
		printf("line: %s\n", line);
		check_map_contents(info, line);
		free(line);
		ret = get_next_line(info->fd, &line);
	}
	free(line);
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
