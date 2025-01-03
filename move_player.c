/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:37:17 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 00:27:11 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	ft_printf("collectible number :  %d\n", game->collectible);
	if (keycode == 119)
	{
		choose_up_down(game, -1);
		ft_printf("UP\n");
	}
	if (keycode == 115)
	{
		choose_up_down(game, 1);
		ft_printf("DOWN\n");
	}
	if (keycode == 100)
	{
		choose_left_right(game, 1);
		ft_printf("RIGHT\n");
	}
	if (keycode == 97)
	{
		choose_left_right(game, -1);
		ft_printf("LEFT\n");
	}
	return (0);
}
