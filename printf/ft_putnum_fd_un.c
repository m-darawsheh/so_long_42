/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_fd_UN.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:19:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/09/12 13:19:53 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnum_fd_un(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnum_fd(n / 10, fd);
		count += ft_putnum_fd(n % 10, fd);
	}
	else
		count += ft_putchar_fd(n + '0', 1);
	return (count);
}
