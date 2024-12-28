/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:20:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/09/12 13:20:15 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		count += ft_putnum_fd(n / 10, fd);
		count += ft_putnum_fd(n % 10, fd);
	}
	else
		count += ft_putchar_fd(n + '0', 1);
	return (count);
}
