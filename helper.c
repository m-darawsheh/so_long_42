/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:08:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/03 19:49:28 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	game->map = NULL;
}

void	free_image(t_game *game)
{
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->bground_img)
		mlx_destroy_image(game->mlx, game->bground_img);
}

void	free_empty_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->empty_map[i]);
		i++;
	}
	free(game->empty_map);
}

void	win_free_fun(char *win_massage, t_game *game)
{
	ft_putendl_fd(win_massage, 1);
	close(game->fd);
	free_map(game);
	free_empty_map(game);
	if (game->sub_map)
	{
		free(game->sub_map);
	}
	free_image(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}

void	ft_on_exit(t_game *game, int keycode)
{
	if (keycode == 119
		&& game->map[game->y_coordinate - 1][game->x_coordinate] == 'E')
	{
		win_free_fun("YOU WIN", game);
	}
	else if (keycode == 115
		&& game->map[game->y_coordinate + 1][game->x_coordinate] == 'E')
	{
		win_free_fun("YOU WIN", game);
	}
	else if (keycode == 100
		&& game->map[game->y_coordinate][game->x_coordinate + 1] == 'E')
	{
		win_free_fun("YOU WIN", game);
	}
	else if (keycode == 97
		&& game->map[game->y_coordinate][game->x_coordinate - 1] == 'E')
	{
		win_free_fun("YOU WIN", game);
	}
}
