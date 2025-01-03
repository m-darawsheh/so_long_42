/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:09:37 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/03 20:22:18 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cheacker_ec_move(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E' && !(game->empty_map[i][j]))
			{
				free_fun("Error\n: Invalid map (Can't move to exit)", game);
			}
			if (game->map[i][j] == 'C' && !(game->empty_map[i][j]))
			{
				free_fun("Error\n: Invalid map "
					"(Can't move to collectible)", game);
			}	
			j++;
		}
		i++;
	}
}

void	empty_map(t_game *game)
{
	int	i;

	i = 0;
	game->empty_map = ft_calloc(game->height, sizeof(int *));
	if (game->empty_map == NULL)
		free_fun("Error\n: calloc failed for empty_map", game);
	while (i < game->height)
	{
		game->empty_map[i] = ft_calloc(game->width, sizeof(int));
		if (game->empty_map[i] == NULL)
			free_fun("Error\n: calloc failed for empty_map row", game);
		i++;
	}
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || game->empty_map[y][x] == 1)
		return ;
	game->empty_map[y][x] = 1;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	can_move(t_game *game)
{
	empty_map(game);
	flood_fill(game, game->x_coordinate, game->y_coordinate);
	cheacker_ec_move(game);
}
