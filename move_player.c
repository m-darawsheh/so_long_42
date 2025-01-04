/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:37:17 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 05:39:48 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		close_window(game);
	}
	if (keycode == 119)
	{
		choose_up_down(game, -1);
	}
	if (keycode == 115)
	{
		choose_up_down(game, 1);
	}
	if (keycode == 100)
	{
		choose_left_right(game, 1);
	}
	if (keycode == 97)
	{
		choose_left_right(game, -1);
	}
	return (0);
}
