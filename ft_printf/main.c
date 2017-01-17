/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <rostroh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:53:48 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/17 15:11:49 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
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
	ft_printf("%u\n", -1);
	printf("%u\n", -1);
//	ft_printf("%d\n", -1);
//	printf("%d\n", -1);
//	ft_printf("%lu", -42);
//	ft_printf("%ld\n", 9223372036854775807);
//	printf("%ld\n", 9223372036854775807);
//	ft_printf("%5.o\n", 0);
//	printf("%5.o\n", 0);
//	ft_printf("%5.2s is a string\n", "this");
//	printf("%5.2s is a string\n", "this");
//	ft_printf("%2c\n", 0);
//	printf("%2c\n", 0);
//	ft_printf("%2.2s\n", "");
//	printf("%2.2s\n", "");
//	ft_printf("%.2s %s %s %.3s\n", "This", "is", "a", "string");
//	printf("%.2s %s %s %.3s\n", "This", "is", "a", "string");
//	ft_printf("%lu\n", -4294967296);
//	printf("%lu\n", -4294967296);
	return (0);
}
