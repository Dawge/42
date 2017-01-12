/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:14 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/12 15:52:19 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include"libft.h"

int		check_diD(char c)
{
	if (c == 'D' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

int		check_xX(char c, int hash)
{
	if ((c == 'x' || c == 'X') && hash == 1)
		return (1);
	return (0);
}

int		print(t_arg params)
{
	int		i;
	char	*cpy;

	i = 0;
	if (params.letter == 's' && params.pres > 0)
	{
		cpy = params.str;
		while (i++ < params.pres)
			ft_putchar(*cpy);
		free(cpy);
		return (params.pres);
	}
	else
	{
		ft_putstr(params.str);
		return (ft_strlen(params.str));
	}
}

int		get_value(t_arg params)
{
	int		value;

	value = 0;
	if (params.letter == 's')
		value = params.pres > 0 ? params.pres : (int)ft_strlen(params.str);
	else
		value = (int)ft_strlen(params.str);
	if ((params.letter == 'X' || params.letter == 'x') && (params.hash == 1))
		value += 2;
	return (value);
}

int		stupidshit(char c)
{
	ft_putchar('0');
	ft_putchar(c);
	return (2);
}

int		print_shit(t_arg params)
{
	int		value;
	int		get_printed;

	get_printed = 0;
	value = get_value(params);
	if (check_xX(params.letter, params.hash) && params.zero == '0')
		get_printed += stupidshit(params.letter);
	while (params.space-- - value > 0 && params.space > 0)
	{
		get_printed++;
		ft_putchar(params.zero);
	}
	if (check_xX(params.letter, params.hash) && params.zero == ' ')
		get_printed += stupidshit(params.letter);
	if (check_diD(params.letter) == 1 && params.pos == 1)
		ft_putchar('+');
	get_printed += print(params);
	while (++params.space + value < 0 && params.space < 0)
	{
		get_printed++;
		ft_putchar(params.zero);
	}
	return (get_printed + params.pos);
}
