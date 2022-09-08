/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:10 by sokim             #+#    #+#             */
/*   Updated: 2022/09/08 13:10:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_line_height(int *start, int *end, t_dda *dda)
{
	int	line_height;

	line_height = (int)(WINDOW_HEIGHT / dda->perp_wall_dist);
	*start = WINDOW_HEIGHT / 2 - line_height / 2;
	if (*start < 0)
		*start = 0;
	*end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (*end >= WINDOW_HEIGHT)
		*end = WINDOW_HEIGHT - 1;
	return (line_height);
}
