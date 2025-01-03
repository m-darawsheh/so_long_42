/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:20:42 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/03 21:45:05 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_xpm_to_file(t_game *game)
{
	int	x;
	int	y;

	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"images/collectible.xpm", &x, &y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"images/exit.xpm", &x, &y);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"images/player.xpm", &x, &y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"images/wall.xpm", &x, &y);
	game->bground_img = mlx_xpm_file_to_image(game->mlx,
			"images/bground.xpm", &x, &y);
}

void	put_image_to_window(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < game->height * game->width)
	{
		x = i % game->width;
		y = i / game->width;
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx, game->win,
				game->collectible_img, x * FACTOR, y * FACTOR);
		if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_img, x * FACTOR, y * FACTOR);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_img, x * FACTOR, y * FACTOR);
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->wall_img, x * FACTOR, y * FACTOR);
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx, game->win,
				game->bground_img, x * FACTOR, y * FACTOR);
	}
}
