/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <rostroh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:27:25 by rostroh           #+#    #+#             */
/*   Updated: 2016/12/18 18:58:52 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include <stdio.h>

int		len_int(int nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len + 1);
}

int		get_arg(const char *format)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (format[i] == 'l' && i < 2)
		i++;
	if (i > 0)
		return (i);
	while (format[j - 2] == 'h' && j < 4)
		j++;
	if (j > 2)
		return (j);
	if (*format == 'j')
		return (5);
	if (*format == 'z')
		return (7);
	return (0);
}

int		put_space(int nb_space, char *str)
{
	int		print;
	int		je_suis_sale;

	print = 0;
	je_suis_sale = 0;
	if (nb_space < 0)
	{
		ft_putstr(str);
		nb_space = -nb_space;
		je_suis_sale = 1;
	}
	while (nb_space - (int)ft_strlen(str) > 0)
	{
		ft_putchar(' ');
		nb_space--;
		print++;
	}
	if (nb_space >= 0 && je_suis_sale == 0)
		ft_putstr(str);
	return (print + ft_strlen(str));
}

int		get_next_char(const char **format, va_list ap)
{
	int		i;
	int		arg;
	char	*str;

	i = 0;
	arg = 0;
	i = ft_atoi(*format);
	if (i != 0)
		*format += len_int(i);
	if (**format == '-')
		(*format)++;
	while (ft_isspace(**format))
		(*format)++;
	arg = get_arg(*format);
	if (arg == 0)
		;
	else if (arg % 2 == 1)
		(*format)++;
	else
		(*format) += 2;
	str = poney(*format, ap, arg);
	return (put_space(i, str));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			tmp;
	int			get_print;

	get_print = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format)
		{
			ft_putchar(*format++);
			get_print++;
		}
		if (*format == '%')
		{
			format++;
			while (ft_isspace(*format))
				format++;
			tmp = get_next_char((&format), ap);
			format++;
			get_print += tmp;
		}
	}
	va_end(ap);
	return (get_print);
}
