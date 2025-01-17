/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:36:06 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/05 15:05:40 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_fun(char *error_massage, t_game *game)
{
	ft_putendl_fd(error_massage, 2);
	if (game->fd != -1)
		close(game->fd);
	if (game->map)
		free_map(game);
	if (game->empty_map)
		free_empty_map(game);
	if (game->sub_map)
		free(game->sub_map);
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
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		ft_dest_mlx(game);
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

	init_game(&game);
	if (argc != 2)
	{
		ft_putendl_fd ("Error\n: Invalid number of arguments", 2);
		return (1);
	}
	parsing_map(&game, argv[1]);
	check_rectangle(&game);
	calculate_size(&game);
	check_wall(&game);
	check_p_e_c(&game);
	find_player(&game);
	exit_place(&game);
	can_move(&game);
	prot_init(&game);
	convert_xpm_to_file(&game);
	put_image_to_window(&game);
	mlx_hook(game.win, 2, 1L << 0, move_player, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
