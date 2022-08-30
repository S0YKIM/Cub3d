/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:41:26 by sokim             #+#    #+#             */
/*   Updated: 2022/08/30 16:54:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "macro.h"
# include <stdio.h>
# include <fcntl.h>

/*
 * Init functions
 */
void	init_info(t_info *info);

/*
 * Check functions
 */
void	check_map_validation(t_info *info);
int		check_map_contents(t_info *info, char *line);
void	check_wall(t_info *info);

/*
 * Identifier functions
 */
int	save_wall_texture(t_info *info, char *line);
int	save_floor_ceiling_color(t_info *info, char *line);

/*
 * Exit functions
 */
void	free_all(char *line, t_info *info);
void	exit_with_free_all(char *msg, char *line, t_info *info);

#endif
