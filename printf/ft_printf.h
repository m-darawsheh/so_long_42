/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:05:36 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/30 11:44:45 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t			ft_strlen_p(char *s);
int				ft_printf(const char *format, ...);
int				ft_putareg(char formater, va_list args);
int				ft_puthex_fd(unsigned long n, char c, int fd);
int				ft_putnum_fd(int n, int fd);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
unsigned int	ft_putnum_fd_un(unsigned int n, int fd);

#endif
