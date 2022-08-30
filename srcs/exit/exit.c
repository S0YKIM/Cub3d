/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 16:42:39 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_line(char *line)
{
	if (line)
		free(line);
}

static void	free_info(t_info *info)
{
	int	i;

	if (!info)
		return ;
	if (info->map.map)
	{
		i = 0;
		while (info->map.map[i])
		{
			free(info->map.map[i]);
			i++;
		}
		free(info->map.map);
	}
	if (info->map.tmp)
		free(info->map.tmp);
	if (info->fd)
		close(info->fd);
	while (info->map.tex_files && info->map.tex_files[i])
	{
		free(info->map.tex_files[i]);
		i++;
	}
}

void	free_all(char *line, t_info *info)
{
	free_line(line);
	free_info(info);
}

void	exit_with_free_all(char *msg, char *line, t_info *info)
{
	free_all(line, info);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
