/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:39:25 by sokim             #+#    #+#             */
/*   Updated: 2022/09/02 13:44:37 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_with_button_close(t_info *info)
{
	ft_putendl_fd("You quit the game.", 2);
	free_all(NULL, info);
	mlx_destroy_window(info->mlx, info->window);
	// mlx_destroy_image();
	exit(EXIT_SUCCESS);
	return (1);
}
