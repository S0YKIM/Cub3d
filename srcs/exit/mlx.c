/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:39:25 by sokim             #+#    #+#             */
/*   Updated: 2022/09/07 16:30:25 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_with_mlx_error(char *msg, t_info *info)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (exit_mlx(info));
}

int	exit_with_button_close(t_info *info)
{
	ft_putendl_fd("You quit the game.", 2);
	return (exit_mlx(info));
}

int	exit_mlx(t_info *info)
{
	int	i;

	i = 0;
	free_all(NULL, info);
	if (info->window)
		mlx_destroy_window(info->mlx, info->window);
	if (info->img->img)
		mlx_destroy_image(info->mlx, info->img->img);
	if (info->img)
		free(info->img);
	while (i < 4)
	{
		if (info->map->textures[i].img)
			mlx_destroy_image(info->mlx, info->map->textures[i++].img);
	}
	exit(EXIT_SUCCESS);
	return (1);
}
