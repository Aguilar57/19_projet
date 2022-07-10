/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:12:49 by jonathan          #+#    #+#             */
/*   Updated: 2022/07/10 07:48:40 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_conditions(str, &params, i, &len);
			i++;
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(params);
	return (len);
}

void	ft_conditions(const char *str, va_list *params, int i, int *len)
{
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(*params, int), len);
	else if (str[i + 1] == 's')
		ft_putstr(va_arg(*params, const char *), len);
	else if ((str[i + 1] == 'd' || str[i + 1] == 'i'))
		ft_putnbr(va_arg(*params, int), len);
	else if (str[i + 1] == '%')
		ft_putchar('%', len);
	else if (str[i + 1] == 'p')
	{
		ft_putstr("0x", len);
		ft_putptr(va_arg(*params, unsigned long), len);
	}
	else if (str[i + 1] == 'u')
		ft_putnbr_u(va_arg(*params, unsigned int), len);
	else if (str[i + 1] == 'X')
		ft_puthexa_cap(va_arg(*params, unsigned long), len);
	else if (str[i + 1] == 'x')
		ft_puthexa(va_arg(*params, unsigned long), len);
}

int main()
{
	// printf("|%i|",printf("et %i", 1));
	// printf("\n");
	// printf("|%i|",ft_printf("et %i", 1));
	// ft_printf("bonjour");
	unsigned int a;
	int n;

	a = 3000000000;
	n = 2147483647;
	printf("%i\n",printf("\nj'ai %i ans %c et %s et %% ! \net a cet adresse : %p %x %X %u\n", n, 'c', "salut", &n, a, a, a));
	printf("%i",ft_printf("\nj'ai %i ans %c et %s et %% ! \net a cet adresse : %p %x %X %u\n", n, 'c', "salut", &n, a, a, a));
}
