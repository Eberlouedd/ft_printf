#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void tranlate_c(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		tranlate_c(str[i]);
		i++;
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

void	parcer(char str, va_list val)
{
	if (str == 'c')
			tranlate_c(va_arg(val, int));
	else if (str == 's')
		ft_putstr(va_arg(val, char *));
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(val, int));
	else if ((str == 'x' || str == 'X'))
		conv_hex(va_arg(val, int), str);
	else if (str == 'u')
		put_unsignednbr(va_arg(val, unsigned int));
	else if (str == '%')
		tranlate_c('%');
	else
	{
		tranlate_c('%');
		tranlate_c(str);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			parcer(str[i + 1], args);
			i++;
		}
		else
			tranlate_c(str[i]);
		i++;
	}
	va_end(args);
}

int main()
{
	
	ft_printf("%o %oui \n");
}
