/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:20:42 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 05:13:23 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->fd = -1;
	game->map = NULL;
	game->empty_map = NULL;
	game->sub_map = NULL;
	game->collectible_img = NULL;
	game->exit_img = NULL;
	game->player_img = NULL;
	game->wall_img = NULL;
	game->bground_img = NULL;
	game->win = NULL;
	game->mlx = NULL;
	game->height = 0;
	game->width = 0;
	game->y_coordinate = 0;
	game->x_coordinate = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	game->x_exit = 0;
	game->y_exit = 0;
	game->number_of_moves = 0;
}

void	ft_dest_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

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
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible_img, j * FACTOR, i * FACTOR);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_img, j * FACTOR, i * FACTOR);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img, j * FACTOR, i * FACTOR);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->bground_img, j * FACTOR, i * FACTOR);
			j++;
		}
		i++;
	}
}
