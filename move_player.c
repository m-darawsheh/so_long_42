/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:37:17 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/02 17:12:44 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	if (game->map[game->y_coordinate + 1][game->x_coordinate] != '1')
	{
		if (game->map[game->y_coordinate + 1][game->x_coordinate] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->x_coordinate * FACTOR, (game->y_coordinate - 1) * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate - 1][game->x_coordinate] = 'P';
			game->y_coordinate--;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate + 1][game->x_coordinate] == '0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->x_coordinate * FACTOR, (game->y_coordinate - 1) * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate - 1][game->x_coordinate] = 'P';
			game->y_coordinate--;
		}
	}
	
}

static void	move_down(t_game *game)
{
	if (game->map[game->y_coordinate - 1][game->x_coordinate] != '1')
	{
		if (game->map[game->y_coordinate - 1][game->x_coordinate] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->x_coordinate * FACTOR, (game->y_coordinate + 1) * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate + 1][game->x_coordinate] = 'P';
			game->y_coordinate++;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate - 1][game->x_coordinate] == '0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->x_coordinate * FACTOR, (game->y_coordinate + 1) * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate + 1][game->x_coordinate] = 'P';
			game->y_coordinate++;
		}
	}
}

static void	move_right(t_game *game)
{
	if (game->map[game->y_coordinate][game->x_coordinate + 1] != '1')
	{
		if (game->map[game->y_coordinate][game->x_coordinate + 1] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, (game->x_coordinate + 1) * FACTOR, game->y_coordinate * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate + 1] = 'P';
			game->x_coordinate++;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate][game->x_coordinate + 1] == '0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, (game->x_coordinate + 1) * FACTOR, game->y_coordinate * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate + 1] = 'P';
			game->x_coordinate++;
		}
	}
}

static void	move_left(t_game *game)
{
	if (game->map[game->y_coordinate][game->x_coordinate - 1] != '1')
	{
		if (game->map[game->y_coordinate][game->x_coordinate - 1] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, (game->x_coordinate - 1) * FACTOR, game->y_coordinate * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate - 1] = 'P';
			game->x_coordinate--;
			game->collectible--;
		}
		else if (game->map[game->y_coordinate][game->x_coordinate - 1] == '0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->player_img, (game->x_coordinate - 1) * FACTOR, game->y_coordinate * FACTOR);
			mlx_put_image_to_window(game->mlx, game->win, game->bground_img, game->x_coordinate * FACTOR, game->y_coordinate * FACTOR);
			game->map[game->y_coordinate][game->x_coordinate] = '0';
			game->map[game->y_coordinate][game->x_coordinate - 1] = 'P';
			game->x_coordinate--;
		}
	}
}

int	move_player(int keycode, t_game *game)
{
		if (keycode == 13)
		{
			move_up(game);
			printf("UP\n");
		}
		if (keycode == 1)
		{
			move_down(game);
			printf("DOWN\n");
		}
		if (keycode == 2)
		{
			move_right(game);
			printf("RIGHT\n");
		}
		if (keycode == 0)
		{
			move_left(game);
			printf("LEFT\n");
		}
		return (0);
}