/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:46:40 by kyacini           #+#    #+#             */
/*   Updated: 2022/06/15 06:23:59 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tranlate_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	translate_i_d(int val)
{
	ft_putnbr(val);
	return (compte_chiffre(val, 10));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		tranlate_c(str[i]);
		i++;
	}
	return (i);
}

void	translate_p(unsigned long int val, int *count)
{
	if (val == 0)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
		return ;
	}
	write(1, "0x", 2);
	*count = *count + 2;
	conv_hexadd(val, count);
}
