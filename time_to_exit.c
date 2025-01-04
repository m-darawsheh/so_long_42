/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:25:45 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 03:13:52 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_place(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->x_exit = x;
				game->y_exit = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	time_to_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->exit_img, game->x_exit * FACTOR, game->y_exit * FACTOR);
}
