/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_protiction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:22:32 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/05 16:37:47 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prot_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_fun("Error\nFailed to initialize mlx\n", game);
	game->win = mlx_new_window(game->mlx,
			(game->width) * FACTOR, (game->height) * FACTOR, "so_long");
	if (!game->win)
		free_fun("Error\nFailed to create window\n", game);
}

void	f1_prot_and_put(t_game *game, char type)
{
	(void)type;
	if (!game->collectible_img)
		free_fun("Error\nFailed to load collectible image\n", game);
	if (!game->player_img)
		free_fun("Error\nFailed to load player image\n", game);
	if (!game->wall_img)
		free_fun("Error\nFailed to load wall image\n", game);
	if (!game->bground_img)
		free_fun("Error\nFailed to load background image\n", game);
	if (!game->exit_img)
		free_fun("Error\nFailed to load background image\n", game);
}

void	f2_prot_and_put(t_game *game, int return_value)
{
	if (return_value == -1)
		free_fun("Error\nFailed to load image\n", game);
}

void	prot_and_put(t_game *game, char type, int x, int y)
{
	int	return_value;

	return_value = 0;
	if (type == 'C')
	{
		return_value = mlx_put_image_to_window(game->mlx, game->win,
				game->collectible_img, x * FACTOR, y * FACTOR);
	}
	else if (type == 'P')
	{
		return_value = mlx_put_image_to_window(game->mlx, game->win,
				game->player_img, x * FACTOR, y * FACTOR);
	}
	else if (type == '1')
	{
		return_value = mlx_put_image_to_window(game->mlx, game->win,
				game->wall_img, x * FACTOR, y * FACTOR);
	}
	else
	{
		return_value = mlx_put_image_to_window(game->mlx, game->win,
				game->bground_img, x * FACTOR, y * FACTOR);
	}
	f2_prot_and_put(game, return_value);
}
