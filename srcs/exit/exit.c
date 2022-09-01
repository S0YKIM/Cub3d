/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/09/01 11:19:12 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_texfiles(t_map *map)
{
	int	i;

	i = 0;
	if (map->tex_files)
	{
		while (map->tex_files[i])
		{
			free(map->tex_files[i]);
			i++;
		}
		free(map->tex_files);
	}
}

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->tmp)
		free(map->tmp);
}

static void	free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->fd)
		close(info->fd);
	free_map(&info->map);
	free_texfiles(&info->map);
}

void	free_all(char *line, t_info *info)
{
	if (line)
		free(line);
	free_info(info);
}

void	exit_with_free_all(char *msg, char *line, t_info *info)
{
	free_all(line, info);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
