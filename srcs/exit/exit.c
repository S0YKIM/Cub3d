/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/08/29 13:02:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_free_all(char *msg, char *line, t_info *info)
{
	int	i;

	if (info->map.map)
	{
		i = 0;
		while (info->map.map[i])
			free(info->map.map[i]);
			i++;
	}
	if (line)
		free(line);
	if (info->fd)
		close(info->fd);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
