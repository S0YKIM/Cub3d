/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 17:56:39 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_free_all(char *msg, char **map, char *line, int fd)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i]);
			i++;
	}
	if (line)
		free(line);
	if (fd)
		close(fd);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
