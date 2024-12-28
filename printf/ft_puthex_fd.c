/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:20:33 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/09/12 13:20:34 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned long n, char c, int fd)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthex_fd(n / 16, c, fd);
		count += ft_puthex_fd(n % 16, c, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else if (c == 'x')
			ft_putchar_fd(n - 10 + 'a', fd);
		else if (c == 'X')
			ft_putchar_fd(n - 10 + 'A', fd);
		count++;
	}
	return (count);
}
