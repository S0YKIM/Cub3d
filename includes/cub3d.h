/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:41:26 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 13:27:49 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "macro.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

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
int		save_wall_texture(t_info *info, char *line);
int		save_floor_ceiling_color(t_info *info, char *line);

/*
 * Exit functions
 */
void	free_all(char *line, t_info *info);
void	exit_with_free_all(char *msg, char *line, t_info *info);
int		exit_with_button_close(t_info *info);
int		exit_with_mlx_error(char *msg, t_info *info);
int		exit_mlx(t_info *info);

/*
 * Hook functions
 */
int		key_down(int keycode, t_info *info);
int		key_up(int keycode, t_info *info);

/*
 * Calculate functions
 */
void	rotate_vector(t_player *player, int angle);
void	rotate_player(t_player *player, char direction);

/*
 * Manipulate player functions
 */
void	set_player_position(t_info *info);

/*
 * Drawing functions
 */
int		draw_frame(t_info *info);

/*
 * DDA functions
 */
void	set_dda(t_dda *dda, t_player *player, double w);
void	find_wall_hit(t_dda *dda, t_info *info);
void	set_perp_wall_dist(t_dda *dda, t_player *player);
int		calc_line_height(int *start, int *end, t_dda *dda);

/*
 * Texturing functions
 */
void	init_texture(t_info *info);
void	calc_texture_offset(t_info *info, t_dda *dda, t_texture *tex);
int		find_tex_num(t_dda *dda);

#endif
