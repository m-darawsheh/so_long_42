/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:36:06 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 02:58:00 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_fun(char *error_massage, t_game *game)
{
	ft_putendl_fd(error_massage, 2);
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
	exit (1);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				game->x_coordinate = i;
				game->y_coordinate = j;
			}
			i++;
		}
		j++;
	}
}

void	calculate_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		i++;
	}
	game->height = i;
	while (game->map[0][j])
	{
		j++;
	}
	game->width = j;
}

int	close_window(t_game *game)
{
	free_fun("Close window \n", game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror ("Error\n: Invalid number of arguments");
		return (1);
	}
	parsing_map(&game, argv[1]);
	check_rectangle(&game);
	calculate_size(&game);
	check_wall(&game);
	check_p_e_c(&game);
	find_player(&game);
	exit_place(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			(game.width) * FACTOR, (game.height) * FACTOR, "so_long");
	can_move(&game);
	convert_xpm_to_file(&game);
	put_image_to_window(&game);
	mlx_hook(game.win, 2, 1L << 0, move_player, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
