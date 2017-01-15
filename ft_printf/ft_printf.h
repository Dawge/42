/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:02:34 by rostroh           #+#    #+#             */
/*   Updated: 2017/01/14 18:09:25 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_arg
{
	int		neg;
	char	cha;
	int		pos;
	int		brt;
	int		hash;
	int		conv;
	int		pres;
	char	*str;
	int		space;
	char	zero;
	char	letter;
}				t_arg;

int			check_diD(char c);
int			check_xX(char c, int hash);
int			len_base(long nb, int base);
char		*get_base(long nb, int base, char c);
int			ft_printf(const char *format, ...);
char		*get_string(t_arg param, va_list ap);
int			print_shit(t_arg params);
char		*abs_string(char *str);
t_arg		set_params(t_arg params);
#endif
