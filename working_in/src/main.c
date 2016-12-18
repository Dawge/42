/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <rostroh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:48 by rostroh           #+#    #+#             */
/*   Updated: 2016/12/18 19:49:36 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>

int			main(int argc, char **argv)
{
	int		i;
	size_t	t;
	wchar_t c;

	i = 42;
	t = 8;
	c = L'芝';
	ft_printf("%lx\n", 4294967296);
	printf("%jx\n", -4294967296);
	return (0);
}
