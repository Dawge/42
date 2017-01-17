/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:14 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/17 16:06:25 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include"libft.h"

int		print(t_arg p)
{
	int		i;
	char	*cpy;

	i = 0;
	if (p.letter == 'c')
	{
		ft_putchar(p.cha);
		return (1);
	}
	if (p.letter == 's' && p.pres < ft_strlen(p.str) && p.pres > 0)
	{
		cpy = p.str;
		while (i++ < p.pres)
		{
			ft_putchar(*cpy);
			cpy++;
		}
		return (p.pres);
	}
	else
	{
		if (ft_strlen(p.str) == 0 && p.space > 0)
		{
			ft_putchar(' ');
			i = 1;
		}
		ft_putstr(p.str);
		return (ft_strlen(p.str) + i);
	}
}

int		get_value(t_arg params)
{
	int		value;

	value = 0;
	if (params.letter == 'c' && params.cha == 0)
		return (1);
	if (params.letter == 's')
	{
		if (ft_strlen(params.str) == 0)
			return (0);
		value = params.pres > 0 ? params.pres : (int)ft_strlen(params.str);
	}
	else
		value = (int)ft_strlen(params.str);
	if ((params.letter == 'X' || params.letter == 'x') && (params.hash == 1))
		value += ft_atoi(params.str) != 0 ? 2 : 0;
	return (value);
}

int		stupidshit(t_arg params)
{
	if (params.hash == 1 && ft_atoi(params.str) != 0)
	{
		ft_putchar('0');
		ft_putchar(params.letter);
		return (2);
	}
	return (0);
}

int		print_shit(t_arg params)
{
	int		tmp;
	int		value;
	int		other_shit;
	int		get_printed;

	get_printed = 0;
/*	value = get_value(params);
	if (check_diD(params.letter))
		value += (params.pres > ft_strlen(params.str) ? params.pres - get_value(params) : 0);
	params = set_params(params);
	other_shit = params.pres > ft_strlen(params.str) ? 0 : params.pres - ft_strlen(params.str);
	if (other_shit < 0 || params.letter == 'c' || params.letter == 's' )
		other_shit = 0;
	tmp = params.space;*/
	if (check_xXoO(params.letter, params.hash) && params.zero == '0')
		get_printed += stupidshit(params);
	if (check_diD(params.letter) == 1 && params.pos == 1 && params.zero == '0')
		ft_putchar('+');
	if (params.zero == '0' && params.neg == 1)
	{
		ft_putchar('-');
		get_printed++;
	}
	while (tmp-- - value - other_shit - params.pos > 0 && tmp > 0)
	{
		get_printed++;
		ft_putchar(params.zero);
	}
	while (params.pres > ft_strlen(params.str) && check_diD(params.letter) == 1)
	{
		get_printed++;
		ft_putchar('0');
		params.pres--;
	}
	if (params.brt == 1 && params.letter == 'd')
	{
		ft_putchar(' ');
		get_printed++;;
	}
	if (params.zero == ' ' && params.neg == 1)
	{
		ft_putchar('-');
		get_printed++;
	}
	get_printed += other_shit;
	if (check_diD(params.letter) == 1 && params.pos == 1 && params.zero != '0')
		ft_putchar('+');
	while (other_shit-- > 0 && check_diD(params.letter) == 1)
		ft_putchar('0');
	if (check_xX(params.letter, params.hash) && params.zero == ' ')
		get_printed += stupidshit(params);
	if (!(params.point == 1 && params.pres == 0) || params.letter == '%')
		get_printed += print(params);
	else
	{
		if (params.letter == 'o' || params.letter == 'O')
		{
			ft_putchar(' ');
			get_printed++;
		}
	}
	while (++tmp + value < 0 && tmp < 0)
	{
		get_printed++;
		ft_putchar(params.zero);
	}
	return (get_printed + params.pos);
}
