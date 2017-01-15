/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:57:08 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/15 16:06:19 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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

char	*abs_string(char *str)
{
	char	*cpy;
	char	*to_return;

	to_return = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!to_return)
		return (NULL);
	cpy = to_return;
	if (*str)
		str++;
	while (*str)
	{
		*cpy = *str;
		str++;
		cpy++;
	}
	*cpy = '\0';
	return (to_return);
}

t_arg	set_params(t_arg params)
{
	char	*cpy;

	cpy = params.str;
	params.cha = *cpy;
	if (ft_atoi(params.str) < 0)
	{
		params.neg = 1;
		params.str = abs_string(params.str);
	}
	if (params.space != 0 || params.pos != 0 || params.neg != 0)
		params.brt = 0;
	return (params);
}
