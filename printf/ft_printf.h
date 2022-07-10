/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:14:14 by jonathan          #+#    #+#             */
/*   Updated: 2022/07/10 07:40:42 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c, int *len);
int		ft_printf(const char *str, ...);
void	ft_putstr(const char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putptr(unsigned long n, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_puthexa(unsigned long n, int *len);
void	ft_puthexa_cap(unsigned long n, int *len);
void	ft_conditions(const char *str, va_list *params, int i, int *len);

#endif