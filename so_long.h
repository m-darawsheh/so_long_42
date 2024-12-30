/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:34:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/30 14:08:35 by mdarawsh         ###   ########.fr       */
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

	int	width;// FOR SIZE OF MAP
	int height;// FOR SIZE OF MAP
}	t_game;

#endif