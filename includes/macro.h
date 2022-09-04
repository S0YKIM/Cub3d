/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:54:10 by sokim             #+#    #+#             */
/*   Updated: 2022/09/04 12:08:45 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*
 * Return value
 */
# define FT_FALSE 0
# define FT_TRUE 1
# define FT_ERROR -1

/*
 * Directions
 */
# define FT_EAST 0
# define FT_WEST 1
# define FT_SOUTH 2
# define FT_NORTH 3

/*
 * Screen size
 */
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 960

/*
 * Event code
 */
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5

/*
 * Key code
 */
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define BUTTON_CLOSE 17

/*
 * Player movement
 */
# define PLAYER_SPEED 0.6

#endif
