/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:02:02 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 00:44:15 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_up_down(t_game *game, int next_move)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->x_coordinate * FACTOR, (game->y_coordinate + next_move) * FACTOR);
	mlx_put_image_to_window(game->mlx, game->win, game->bground_img,
		game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
}

void	choose_up_down(t_game *game, int next_move)
{
	if (game->map[game->y_coordinate + next_move]
		[game->x_coordinate] != '1')
	{
		if (game->map[game->y_coordinate + next_move]
			[game->x_coordinate] == 'C')
		{
			image_up_down(game, next_move);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate + next_move][game->x_coordinate] = 'P';
			game->y_coordinate += next_move;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate + next_move]
			[game->x_coordinate] == '0')
		{
			image_up_down(game, next_move);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate + next_move][game->x_coordinate] = 'P';
			game->y_coordinate += next_move;
		}
		else if (game->map[game->y_coordinate + next_move]
			[game->x_coordinate] == 'E'
			&& game->collectible == 0)
			win_free_fun("YOU WIN", game);
	}
}

void	image_left_right(t_game *game, int next_move)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		(game->x_coordinate + next_move) * FACTOR, game->y_coordinate * FACTOR);
	mlx_put_image_to_window(game->mlx, game->win, game->bground_img,
		game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
}

void	choose_left_right(t_game *game, int next_move)
{
	if (game->map[game->y_coordinate]
		[game->x_coordinate + next_move] != '1')
	{
		if (game->map[game->y_coordinate]
			[game->x_coordinate + next_move] == 'C')
		{
			image_left_right(game, next_move);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate + next_move] = 'P';
			game->x_coordinate += next_move;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate]
			[game->x_coordinate + next_move] == '0')
		{
			image_left_right(game, next_move);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate + next_move] = 'P';
			game->x_coordinate += next_move;
		}
		else if (game->map[game->y_coordinate]
			[game->x_coordinate + next_move] == 'E'
			&& game->collectible == 0)
			win_free_fun("YOU WIN", game);
	}
}
