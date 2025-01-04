/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:02:02 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 05:23:59 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_up_down(t_game *game, int next_move)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->x_coordinate * FACTOR, (game->y_coordinate + next_move) * FACTOR);
	mlx_put_image_to_window(game->mlx, game->win, game->bground_img,
		game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
	game->map[game->y_coordinate][game->x_coordinate] = '0';
	game->map[game->y_coordinate + next_move][game->x_coordinate] = 'P';
	game->y_coordinate += next_move;
}

void	choose_up_down(t_game *game, int next_move)
{
	if (game->map[game->y_coordinate + next_move]
		[game->x_coordinate] != '1')
	{
		game->number_of_moves++;
		ft_printf("Number of moves: %d\n", game->number_of_moves);
		if (game->collectible == 0)
			time_to_exit(game);
		if (game->map[game->y_coordinate + next_move]
			[game->x_coordinate] == 'C')
		{
			image_up_down(game, next_move);
			game->collectible--;
		}
		else if (game->y_coordinate + next_move == game->y_exit
			&&game->x_coordinate == game->x_exit
			&& game->collectible == 0)
			win_free_fun("YOU WIN", game);
		else
			image_up_down(game, next_move);
	}
}

void	image_left_right(t_game *game, int next_move)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		(game->x_coordinate + next_move) * FACTOR, game->y_coordinate * FACTOR);
	mlx_put_image_to_window(game->mlx, game->win, game->bground_img,
		game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
	game->map[game->y_coordinate][game->x_coordinate] = '0';
	game->map[game->y_coordinate][game->x_coordinate + next_move] = 'P';
	game->x_coordinate += next_move;
}

void	choose_left_right(t_game *game, int next_move)
{
	if (game->map[game->y_coordinate]
		[game->x_coordinate + next_move] != '1')
	{
		game->number_of_moves++;
		ft_printf("Number of moves: %d\n", game->number_of_moves);
		if (game->collectible == 0)
			time_to_exit(game);
		if (game->map[game->y_coordinate]
			[game->x_coordinate + next_move] == 'C')
		{
			image_left_right(game, next_move);
			game->collectible--;
		}
		else if (game->x_coordinate + next_move == game->x_exit
			&&game->y_coordinate == game->y_exit
			&& game->collectible == 0)
			win_free_fun("YOU WIN", game);
		else
			image_left_right(game, next_move);
	}
}
