/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:03:29 by sokim             #+#    #+#             */
/*   Updated: 2022/09/09 12:09:05 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_texture(t_info *info)
{
	char	**paths;
	t_img	*textures;
	int		i;

	paths = info->map->tex_files;
	textures = info->map->textures;
	i = 0;
	while (i < 4)
	{
		textures[i].img = mlx_xpm_file_to_image(info->mlx, paths[i], \
			&info->map->textures[i].width, &info->map->textures[i].height);
		if (!textures[i].img)
			exit_with_mlx_error("Failed to convert xpm file to image.", info);
		textures[i].data = (char *)mlx_get_data_addr(textures[i].img, &textures[i].bpp, &textures[i].line_length, &textures[i].endian);
		if (!textures[i].data)
			exit_with_mlx_error("Failed to get address of texture.", info);
		i++;
	}
}
