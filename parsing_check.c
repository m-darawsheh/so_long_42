/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:31:15 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/31 21:57:53 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_P_E_C(t_game *game)
{
	int	i;

	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	while(game->sub_map[i])
	{
		if(game->sub_map[i] == 'P')
			game->player++;
		if(game->sub_map[i] == 'E')
			game->exit++;
		if(game->sub_map[i] == 'C')
			game->collectible++;
		i++;
	}
	if(game->player != 1 || game->exit != 1 || game->collectible < 1)
		free_fun("Error\n: Invalid map (P, E, C)", game);
}

void	check_rectangle(t_game *game)
{
	size_t	i;
	size_t	width_temp;

	i = 0;
	width_temp = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (width_temp != ft_strlen(game->map[i]))
		{
			free_fun("Error\n: Invalid map (Rectangle)", game);
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->sub_map == NULL)
	{
		free_fun("Error\n: Invalid map is empty", game);
	}
	while (game->sub_map[i])
	{
		if (game->sub_map[i] == '\n' && game->sub_map[i + 1] == '\n')
		{
			free_fun("Error\n: Invalid map (Empty line)", game);
		}
		if (!(game->sub_map[i] != '1' || game->sub_map[i] != '0' || game->sub_map[i] != 'P' || game->sub_map[i] != 'E' || game->sub_map[i] != 'C'))
		{
			free_fun("Error\n: Invalid map (Invalid element)", game);
		}
		i++;
	}
}

void	check_extension(char *file, t_game *game)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
	{
		free_fun("Error\n: Invalid file extension", game);
	}
}

void	parsing_map(t_game *game, char *file)
{
	char	*tmp;

	check_extension(file, game);
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
	{
		free_fun("Error\n: File not found", game);
	}
	tmp = get_next_line(game->fd);
	game->sub_map = ft_strdup("");
	while (tmp)
	{
		game->sub_map = ft_strjoin(game->sub_map, tmp);
		free(tmp);
		tmp = get_next_line(game->fd);
	}
	free(tmp);
	check_map(game);
	game->map = ft_split(game->sub_map, '\n');
	if(game->map == NULL)
		free_fun("Error\n: Invalid map", game);
}
