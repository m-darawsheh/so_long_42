/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:08:15 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/31 20:16:00 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_first_row(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0')
	{
		if(game->map[0][i] != '1')
		{
			free_fun("Error\n: Invalid map (Wall) first row", game);
		}
		i++;
	}
}

static void	check_last_row(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[game-> height - 1][i] != '\0')
	{
		if(game->map[game->height - 1][i] != '1')
		{
			free_fun("Error\n: Invalid map (Wall) last row", game);
		}
		i++;
	}
}

static void	check_first_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height && game->map[i][0])
	{
		if(game->map[i][0] != '1')
		{
			free_fun("Error\n: Invalid map (Wall) first column", game);
		}
		i++;
	}
}

static void	check_last_column(t_game *game)
{
	int	i;

	i = 0;
	while ( i < game->height && game->map[i][game->width - 1])
	{
		if(game->map[i][game->width - 1] != '1')
		{
			free_fun("Error\n: Invalid map (Wall) last column", game);
		}
		i++;
	}
}

void	check_wall(t_game *game)
{
	check_first_row(game);
	check_last_column(game);
	check_last_row(game);
	check_first_column(game);
}
