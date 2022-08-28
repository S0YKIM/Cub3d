/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:55:11 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 15:55:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_err_msg(char *msg, char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i]);
			i++;
	}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	exit_with_fd_close(char *msg, char *line, int fd)
{
	if (line)
		free(line);
	close(fd);
	exit_with_err_msg(msg, NULL);
}
