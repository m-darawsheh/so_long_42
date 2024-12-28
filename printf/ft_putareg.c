/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putareg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:18:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/09/12 13:18:56 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putareg(char formater, va_list args)
{
	void	*ptr;

	if (formater == 'd' || formater == 'i')
		return (ft_putnum_fd(va_arg(args, int), 1));
	if (formater == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (formater == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (formater == 'u')
		return (ft_putnum_fd_un(va_arg(args, unsigned int), 1));
	if (formater == 'x' || formater == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), formater, 1));
	if (formater == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr_fd("(nil)", 1));
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		return (ft_puthex_fd((unsigned long)ptr, 'x', 1) + 2);
	}
	if (formater == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
