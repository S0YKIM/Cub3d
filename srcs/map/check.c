/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:15:55 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 18:22:22 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_preconditions(t_map *map, t_info *info, char *line)
{
	int	i;

	if (info->map->flag == FT_TRUE)
		return ;
	i = 0;
	while (i < 4)
	{
		if (!map->tex_files[i])
			exit_with_free_all("Not enough texture info.", line, info);
		i++;
	}
	if (map->floor == FT_ERROR)
		exit_with_free_all("Invalid color type.", line, info);
	if (map->ceiling == FT_ERROR)
		exit_with_free_all("Invalid color type.", line, info);
	info->map->flag = FT_TRUE;
}

static void	check_undefined_letter(t_info *info, char *line, int i)
{
	if (!ft_strchr(" EWSN01", line[i]))
		exit_with_free_all("Invalid map contents.", line, info);
}

static void	make_map(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		check_undefined_letter(info, line, i);
		check_preconditions(info->map, info, line);
		i = 0;
		while (line[i])
		{
			check_undefined_letter(info, line, i);
			i++;
		}
		if (i > info->map->width)
			info->map->width = i;
		info->map->tmp = ft_strjoin_free(info->map->tmp, line, 'L');
		info->map->tmp = ft_strjoin_free(info->map->tmp, "\n", 'L');
		if (info->map->start == 0)
			info->map->start = info->map->end;
	}
}

int	check_map_contents(t_info *info, char *line)
{
	if (!line || line[0] == '\0')
		return (FT_FALSE);
	if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) \
	|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3))
		return (save_wall_texture(info, line));
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (save_floor_ceiling_color(info, line));
	make_map(info, line);
	return (FT_TRUE);
}
