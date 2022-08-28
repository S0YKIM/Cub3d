/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:35:09 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 15:55:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_file_name(char *path)
{
	int		fd;
	t_map	map;

	if (!path || ft_strcmp(path + ft_strlen(path) - 4, ".cub") != 0)
		exit_with_err_msg("ERROR: Invalid file name.", NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_with_err_msg("ERROR: Cannot find the file.", NULL);
	check_map_validation(fd, &map);
	return (fd);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_with_err_msg("ERROR: Invalid number of arguments.", NULL);
	fd = open_file_name(argv[1]);
	
	return (0);
}
