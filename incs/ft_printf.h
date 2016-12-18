/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:20:35 by rostroh           #+#    #+#             */
/*   Updated: 2016/12/18 19:07:31 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

void	ft_putwchar(int c);
void	ft_putwstr(wchar_t str);
int		len_base(long nb, int base);
int		len_int(int nb);
int		print_base(long nb, char c, int base, int param);
char	*get_base(long nb, int base, char c);
char	*poney(const char *format, va_list ap, int arg);
int		ft_printf(const char *format, ...);
#endif
