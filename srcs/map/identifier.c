/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:22:14 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 16:23:03 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_wall_texture(t_info *info, char *line)
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

int	save_floor_ceiling_color(t_info *info, char *line)
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
