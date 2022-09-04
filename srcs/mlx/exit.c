/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:39:25 by sokim             #+#    #+#             */
/*   Updated: 2022/09/04 18:00:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_with_button_close(t_info *info)
{
	ft_putendl_fd("You quit the game.", 2);
	free_all(NULL, info);
	if (info->window)
		mlx_destroy_window(info->mlx, info->window);
	if (info->img->img)
		mlx_destroy_image(info->mlx, info->img->img);
	if (info->img)
		free(info->img);
	exit(EXIT_SUCCESS);
	return (1);
}
