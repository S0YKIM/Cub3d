/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 11:16:29 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_free_all(char *msg, char *line, t_info *info)
{
	int	i;

	if (info && info->map.map)
	{
		i = 0;
		while (info->map.map[i])
		{
			free(info->map.map[i]);
			i++;
		}
		free(info->map.map);
	}
	if (line)
		free(line);
	if (info && info->fd)
		close(info->fd);
	i = 0;
	while (info && info->map.tex_files && info->map.tex_files[i])
		free(info->map.tex_files[i]);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
