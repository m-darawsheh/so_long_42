/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:34:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/01 09:43:30 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include "../libft/get_next_line.h"
#define FACTOR 50

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	char		*sub_map;
	char		**map;
	int			width;
	int			height;
	int			player;
	int			exit;
	int			collectible;
	int			x_coordinate;
	int			y_coordinate;
	int			**empty_map;
}	t_game;

void	check_wall(t_game *game);
void	check_P_E_C(t_game *game);
void	check_rectangle(t_game *game);
void	check_map(t_game *game);
void	check_extension(char *file, t_game *game);
void	parsing_map(t_game *game, char *file);
void free_fun(char *error_massage, t_game *game);
void	find_player(t_game *game);
void	calculate_size(t_game *game);
void	empty_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	can_move(t_game *game);
#endif