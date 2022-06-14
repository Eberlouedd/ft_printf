#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int tranlate_c(char c)
{
	write(1, &c, 1);
	return (1);
}

void	put_unsignednbr(unsigned int nb)
{
	if (nb > 9)
	{
		put_unsignednbr(nb / 10);
		put_unsignednbr(nb % 10);
	}
	if (nb <= 9)
	{
		tranlate_c(nb + '0');
	}
}

void	put_unsignednbrsss(unsigned long int nb)
{
	if (nb > 9)
	{
		put_unsignednbr(nb / 10);
		put_unsignednbr(nb % 10);
	}
	if (nb <= 9)
	{
		tranlate_c(nb + '0');
	}
}

void	conv_hex(int nb, char minmaj)
{
	char	*hex;
	if(minmaj == 'X')
		hex = "0123456789ABCDF";
	else
		hex = "0123456789abcdef";
	if (nb > 16)
	{
		conv_hex(nb / 16, minmaj);
		conv_hex(nb % 16, minmaj);
	}
	else
		tranlate_c(hex[nb]);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		tranlate_c(str[i]);
		i++;
	}
	return (i);
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
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int	translate_i_d(int val)
{
	ft_putnbr(val);
	return (compte_chiffre(val, 10));
}

int translate_u(unsigned int val)
{
	put_unsignednbr(val);
	return (compte_chiffre(val, 10));
}

int	translate_x_X(int val, char str)
{
	conv_hex(val, str);
	return (compte_chiffre(val, 16));
}

void	parcer(char str, va_list val, int *count)
{
	if (str == 'c')
		*count = *count + tranlate_c(va_arg(val, int));
	else if (str == 's')
		*count = *count + ft_putstr(va_arg(val, char *));
	else if (str == 'd' || str == 'i')
		*count = *count + translate_i_d(va_arg(val, int));
	else if ((str == 'x' || str == 'X'))
		*count = *count + translate_x_X(va_arg(val, int), str);
	else if (str == 'u')
		*count = *count + translate_u(va_arg(val, unsigned int));
	else if (str == '%')
		*count = *count + tranlate_c('%');
	else
	{
		tranlate_c('%');
		tranlate_c(str);
		*count = *count + 2;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	count;

	i = 0;
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

int main()
{
	int a = 7;
	int *p = &a;
	put_unsignednbr(p);
	//printf("%d\n" ,ft_printf("%x  %%% %X", 3457, 3457));
}
