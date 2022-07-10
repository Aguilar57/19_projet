/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:12:43 by jonathan          #+#    #+#             */
/*   Updated: 2022/07/10 07:41:20 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long n, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthexa(n / 16, len);
	}
	ft_putchar(hexa[n % 16], len);
}

void	ft_puthexa_cap(unsigned long n, int *len)
{
	char	*hexa_cap;

	hexa_cap = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthexa_cap(n / 16, len);
	}
	ft_putchar(hexa_cap[n % 16], len);
}
