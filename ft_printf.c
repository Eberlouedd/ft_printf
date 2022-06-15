/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:46:26 by kyacini           #+#    #+#             */
/*   Updated: 2022/06/15 06:34:42 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	parcer(char str, va_list val, int *count)
{
	if (str == 'c')
		*count = *count + tranlate_c(va_arg(val, int));
	else if (str == 's')
		*count = *count + ft_putstr(va_arg(val, char *));
	else if (str == 'd' || str == 'i')
		*count = *count + translate_i_d(va_arg(val, int));
	else if ((str == 'x' || str == 'X'))
		conv_hex(va_arg(val, int), str, count);
	else if (str == 'p')
		translate_p(va_arg(val, unsigned long int), count);
	else if (str == 'u')
		put_unsignednbr(va_arg(val, unsigned int), count);
	else if (str == '%')
		*count = *count + tranlate_c('%');
	else
		*count = tranlate_c('%') + tranlate_c(str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			parcer(str[i + 1], args, &count);
			i++;
		}
		else
		{
			tranlate_c(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
