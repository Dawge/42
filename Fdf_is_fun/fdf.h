/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:17:07 by rostroh           #+#    #+#             */
/*   Updated: 2017/03/20 16:55:20 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define WIDTH 1280
# define HEIGTH 720

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				stop;
}					t_point;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e2;
	int				err;
}					t_bres;

typedef struct		s_wipa
{
	void			*mlx;
	void			*win;
}					t_wipa;

typedef struct		s_hook
{
	int				vz;
	int				px;
	int				py;
	int				val;
	int				color;
	t_wipa			pam;
	t_point			**p;
	t_point			**save;
	int				nb_line;
}					t_hook;

/*
** file main.c
*/
int					put_error(int fd);
int					gestion(char *str);
char				*get_fd(char *argv, int *nb);

/*
** file aled.c
*/
int					pol(char *str);
void				print_point(t_point **p, int nb_line, int nb_point);
char				*get_line_i(char *str, int i);
t_point				**creat_point(char *str, int nb_line);

/*
** file draw.c
*/
void				draw_it(t_point **p, int nb_line, t_wipa pam, int color);
t_point				**new_value(t_point **p, t_point **save, t_hook hk);
void				draw_call(t_point **p, t_point **save, int nb_line, \
		char *name);

/*
** file hook.c
*/
int					hook_fonct(int keycode, void *param);

/*
** file draw_line.c
*/
void				draw_line(t_point p1, t_point p2, t_wipa pam, int color);
#endif
