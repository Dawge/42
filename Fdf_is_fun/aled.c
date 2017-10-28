/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aled.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:16:07 by rostroh           #+#    #+#             */
/*   Updated: 2017/03/19 18:23:14 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*get_line_i(char *str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (*str == '\n')
			j++;
		str++;
	}
	return (str);
}

int			pol(char *str)
{
	int		check;
	int		to_return;

	check = 0;
	to_return = 0;
	while (*str != '\n')
	{
		if (ft_isdigit(*str) == 1 && check == 0)
		{
			to_return++;
			check = 1;
		}
		if (*str == ' ')
			check = 0;
		str++;
	}
	return (to_return);
}

int			just_norm_fdf(char c)
{
	return (-1);
}

t_point		*get_point(char *str, int nb_point, t_point *p, int y)
{
	int			i;
	int			neg;
	t_point		*cpy;

	i = 0;
	cpy = p;
	while (i < nb_point)
	{
		neg = 1;
		(p[i]).x = i;
		(p[i]).y = y;
		(p[i]).z = 0;
		if (*str == '-')
			neg = just_norm_fdf(*str++);
		while (ft_isdigit(*str) == 1)
			(p[i]).z = (p[i]).z * 10 + *str++ - '0';
		(p[i]).z *= neg;
		while (*str == ' ')
			str++;
		(p[i]).stop = 1;
		i++;
	}
	(p[i]).stop = -1;
	return (p);
}

t_point		**creat_point(char *str, int nb_line)
{
	int			i;
	int			truc;
	t_point		**p;
	char		*tmp;

	i = 0;
	p = (t_point **)malloc(sizeof(t_point *) * nb_line);
	if (!p)
		return (NULL);
	truc = pol(str);
	while (i < nb_line)
	{
		p[i] = (t_point *)malloc(sizeof(t_point) * pol(str) + 1);
		if (!p[i])
			return (NULL);
		p[i] = get_point(str, pol(str), p[i], i);
		i++;
		str = get_line_i(str, 1);
	}
	return (p);
}
