/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_protiction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:22:32 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 11:05:31 by mdarawsh         ###   ########.fr       */
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

void	f_prot_and_put(t_game *game, char type)
{
	if (type == 'C')
		if (!game->collectible_img)
			free_fun("Error\nFailed to load collectible image\n", game);
	if (type == 'P')
		if (!game->player_img)
			free_fun("Error\nFailed to load player image\n", game);
	if (type == '1')
		if (!game->wall_img)
			free_fun("Error\nFailed to load wall image\n", game);
	if (type == '0')
		if (!game->bground_img)
			free_fun("Error\nFailed to load background image\n", game);
}

void	prot_and_put(t_game *game, char type, int x, int y)
{
	if (type == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * FACTOR, y * FACTOR);
		f_prot_and_put(game, type);
	}
	else if (type == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * FACTOR, y * FACTOR);
		f_prot_and_put(game, type);
	}
	else if (type == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * FACTOR, y * FACTOR);
		f_prot_and_put(game, type);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->bground_img, x * FACTOR, y * FACTOR);
		f_prot_and_put(game, type);
	}
}
