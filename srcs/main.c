/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:35:09 by sokim             #+#    #+#             */
/*   Updated: 2022/08/28 11:42:30 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_err_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (FT_TRUE);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
		return (print_err_msg("Invalid number of arguments."));
	return (0);
}
