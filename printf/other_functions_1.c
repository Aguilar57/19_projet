/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:13:15 by jonathan          #+#    #+#             */
/*   Updated: 2022/07/10 07:41:01 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(const char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * (-1);
		write(1, "-", 1);
		*len = *len + 1;
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
	}
	ft_putchar(nbr % 10 + '0', len);
}

void	ft_putptr(unsigned long n, int *len)
{
	char	*hexa_p;

	hexa_p = "0123456789abcdef";
	if (n > 15)
	{
		ft_putptr(n / 16, len);
	}
	ft_putchar(hexa_p[n % 16], len);
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10, len);
	}
	ft_putchar((n % 10) + '0', len);
}
