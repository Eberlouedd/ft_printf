/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:46:48 by kyacini           #+#    #+#             */
/*   Updated: 2022/06/15 06:34:23 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsignednbr(unsigned long int nb, int *count)
{
	if (nb > 9)
	{
		put_unsignednbr(nb / 10, count);
		put_unsignednbr(nb % 10, count);
	}
	if (nb <= 9)
	{
		tranlate_c(nb + '0');
		*count = *count + 1;
	}
}

void	conv_hex(unsigned int nb, char minmaj, int *count)
{
	char	*hex;

	if (minmaj == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
	{
		conv_hex(nb / 16, minmaj, count);
		conv_hex(nb % 16, minmaj, count);
	}
	else
	{
		tranlate_c(hex[nb]);
		*count = *count + 1;
	}
}

void	conv_hexadd(unsigned long int nb, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		conv_hexadd(nb / 16, count);
		conv_hexadd(nb % 16, count);
	}
	else
	{
		tranlate_c(hex[nb]);
		*count = *count + 1;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9 && nb != -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb <= 9 && nb != -2147483648)
	{
		tranlate_c(nb + '0');
	}
}

int	compte_chiffre(int nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
