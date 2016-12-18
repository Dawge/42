/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poney.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <rostroh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:46:16 by rostroh           #+#    #+#             */
/*   Updated: 2016/12/18 19:49:25 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*poney2(const char *format, va_list ap)
{
	char			*str;

	str = (char*)malloc(sizeof(char) * 2);
	str[1] = '\0';
	if (*format == 'c')
		str[0] = va_arg(ap, unsigned int);
	if (*format == '%')
		str[0] = '%';
	else
		str = NULL;
	return (str);
}

char	*poney(const char *format, va_list ap, int arg)
{
	if (*format == 'd' || *format == 'i')
	{
		if (arg == 1)
			return (get_base(va_arg(ap, long), 10, '.'));
		if (arg == 2)
			return (get_base(va_arg(ap, long long), 10, '.'));
		if (arg == 5)
			return (get_base(va_arg(ap, intmax_t), 10, '.'));
		if (arg == 7)
			return (get_base(va_arg(ap, size_t), 10, '.'));
		return (get_base(va_arg(ap, int), 10, '.'));
	}
	if (*format == 'D')
		return (get_base(va_arg(ap, long), 10, '.'));
	if (*format == 'u')
	{
		if (arg == 1)
			return (get_base(va_arg(ap, long), 10, '.'));
		if (arg == 2)
			return (get_base(va_arg(ap, long long), 10, '.'));
		if (arg == 5)
			return (get_base(va_arg(ap, uintmax_t), 10, '.'));
		if (arg == 7)
			return (get_base(va_arg(ap, size_t), 10, '.'));
		return (get_base(va_arg(ap, unsigned int), 10, '.'));
	}
	if (*format == 'U')
		return (get_base(va_arg(ap, unsigned long), 10, '.'));
	if (*format == 'p')
		return (ft_strcat("0x", get_base(va_arg(ap, unsigned long), 16, 'a')));
	if (*format == 'x' || *format == 'X')
	{
		if (arg == 1)
			return (get_base(va_arg(ap, unsigned long), 16, (*format) - 23));
		if (arg == 2)
			return (get_base(va_arg(ap, unsigned long long), 16, (*format) - 23));
		if (arg == 5)
			return (get_base(va_arg(ap, uintmax_t), 16, (*format) - 23));
		return (get_base(va_arg(ap, unsigned int), 16, (*format) - 23));
	}
	if (*format == 'o')
		return (get_base(va_arg(ap, int), 8, '.'));
	if (*format == 'O')
		return (get_base(va_arg(ap, long), 8, '.'));
	if (*format == 's')
		return (va_arg(ap, char *));
	return (poney2(format, ap));
}
