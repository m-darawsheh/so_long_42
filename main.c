/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:36:06 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/30 19:04:22 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->sub_map == NULL)
	{
		perror ("Error\n: Invalid map");
		exit (1);
	}
	while (game->sub_map[i])
	{
		if (game->sub_map[i] == '\n' && game->sub_map[i + 1] == '\n')
		{
			perror ("Error\n: Invalid map (Empty line)");
			exit (1);
		}
		if (!(game->sub_map[i] != '1' || game->sub_map[i] != '0' || game->sub_map[i] != 'P' || game->sub_map[i] != 'E' || game->sub_map[i] != 'C'))
		{
			perror ("Error\n: Invalid map (Invalid element)");
			exit (1);
		}
		i++;
	}
}

void check_extension(char *file)
{  
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
	{
		perror ("Error\n: Invalid file extension");
		exit(1);
	}
}

void	parsing_map(t_game **game, char *file)
{
	char	*tmp;

	check_extension(file);
	(*game)->fd = open(file, O_RDONLY);
	if ((*game)->fd == -1)
	{
		perror ("Error\n: File not found");
		exit (1);
	}
	tmp = get_next_line((*game)->fd);//for first line
	(*game)->sub_map = ft_calloc(1, 1);
	while (tmp)
	{
		(*game)->sub_map = ft_strjoin((*game)->sub_map, tmp);
		free(tmp);
		tmp = get_next_line((*game)->fd);
	}
	check_map(*game);
	(*game)->map = ft_split((*game)->sub_map, '\n');
	free((*game)->sub_map);
	(*game)->sub_map = NULL;
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
			perror ("Error\n: Invalid map (Rectangle)");
			exit (1);
		}
		i++;
	}
}

void	calculate_size(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while((*game)->map[i])
	{
		i++;
	}
	(*game)->height = i * FACTOR;
	while ((*game)->map[0][j])
	{
		j++;
	}
	(*game)->width = j * FACTOR;
}

int main(int argc, char **argv)
{
	t_game *game;
	if (argc != 2)
	{
		perror ("Error\n: Invalid number of arguments");
		return (1);
	}
	game = malloc(sizeof(t_game));
	parsing_map(&game, argv[1]);

	check_rectangle(game);

	calculate_size(&game);
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Hello, MiniLibX!");
	mlx_loop(game->mlx);
	return 0;
}

