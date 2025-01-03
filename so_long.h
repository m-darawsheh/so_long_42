/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:34:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/03 20:39:25 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../libft/get_next_line.h"
# include <stdbool.h>
# define FACTOR 50
# define UP_MOVE 13
# define DOWN_MOVE 1
# define LEFT_MOVE 0
# define RIGHT_MOVE 2

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*collectible_img;
	void		*exit_img;
	void		*player_img;
	void		*wall_img;
	void		*bground_img;
	char		*sub_map;
	char		**map;
	int			fd;
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
void	check_p_e_c(t_game *game);
void	check_rectangle(t_game *game);
void	check_map(t_game *game);
void	check_extension(char *file, t_game *game);
void	parsing_map(t_game *game, char *file);
void	free_fun(char *error_massage, t_game *game);
void	find_player(t_game *game);
void	calculate_size(t_game *game);
void	empty_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	can_move(t_game *game);
void	cheacker_ec_move(t_game *game);
void	convert_xpm_to_file(t_game *game);
void	put_image_to_window(t_game *game);
int		move_player(int keycode, t_game *game);
void	free_map(t_game *game);
void	free_image(t_game *game);
void	free_empty_map(t_game *game);
void	ft_on_exit(t_game *game, int keycode);
void	win_free_fun(char *win_massage, t_game *game);
#endif