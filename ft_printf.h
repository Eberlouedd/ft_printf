/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:48:02 by kyacini           #+#    #+#             */
/*   Updated: 2022/06/15 06:22:55 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		tranlate_c(char c);
int		translate_i_d(int val);
int		ft_putstr(char *str);
void	conv_hexadd(unsigned long int nb, int *count);
void	put_unsignednbr(unsigned long int nb, int *count);
void	conv_hex(unsigned int nb, char minmaj, int *count);
int		compte_chiffre(int nb, int base);
void	ft_putnbr(int nb);
void	parcer(char str, va_list val, int *count);
int		ft_printf(const char *str, ...);
void	translate_p(unsigned long int val, int *count);

#endif