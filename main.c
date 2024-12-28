/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:36:06 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/28 04:27:22 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
    void *mlx;

    mlx = mlx_init();
    (void)mlx_new_window(mlx, 800, 600, "Hello, MiniLibX!");
    mlx_loop(mlx);
    return 0;
}
