/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:35:09 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 13:10:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_file_name(char *path, t_info *info)
{
	if (!path || ft_strcmp(path + ft_strlen(path) - 4, ".cub") != 0)
		exit_with_free_all("Invalid file name.", NULL, info);
	info->fd = open(path, O_RDONLY);
	if (info->fd < 0)
		exit_with_free_all("Cannot find the file.", NULL, info);
	check_map_validation(info);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		exit_with_free_all("Invalid number of arguments.", NULL, &info);
	init_info(&info);
	open_file_name(argv[1], &info);
	close(info.fd);
	return (0);
}
