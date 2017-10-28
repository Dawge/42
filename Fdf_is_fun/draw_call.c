/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:09:08 by rostroh           #+#    #+#             */
/*   Updated: 2017/03/20 17:17:37 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**center(t_point **p, int nb_line, int value, int px)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while ((p[i][j]).stop != -1)
		{
			(p[i][j]).x += WIDTH / 3 + px;
			(p[i][j]).y += HEIGTH / 4;
			j++;
		}
		i++;
	}
	return (p);
}

t_point		**get_mini(t_point **p, int nb_line, int px)
{
	int		i;
	int		j;
	int		min;

	min = (p[0][0]).x;
	while (i < nb_line)
	{
		j = 0;
		while ((p[i][j]).stop != -1)
		{
			if ((p[i][j]).x < min)
				min = (p[i][j]).x;
			j++;
		}
		i++;
	}
	p = center(p, nb_line, min, px);
	return (p);
}

t_point		**new_value(t_point **p, t_point **save, t_hook hk)
{
	int		i;
	int		j;
	int		aka;
	t_point	new;
	t_point	tmp;

	i = 0;
	while (i < hk.nb_line)
	{
		j = 0;
		while ((p[i][j]).stop != -1)
		{
			new.x = ((save[i][j]).x - (save[i][j]).y) * 250 / 13;
			new.y = ((save[i][j]).x + (save[i][j]).y) * 250 / 13 + hk.py * 3;
			new.z = (save[i][j]).z;
			new.y = (new).y - ((new).z * (hk.vz));
			p[i][j] = new;
			j++;
		}
		i++;
	}
	p = get_mini(p, hk.nb_line, hk.px * 3);
	return (p);
}

void		draw_it(t_point **p, int nb_line, t_wipa pam, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line - 1)
	{
		j = 0;
		while ((p[i][j + 1]).stop != -1)
		{
			draw_line(p[i][j], p[i][j + 1], pam, color);
			draw_line(p[i][j], p[i + 1][j], pam, color);
			draw_line(p[nb_line - 1][j], p[nb_line - 1][j + 1], pam, color);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < nb_line - 1)
	{
		draw_line(p[i][j], p[i + 1][j], pam, color);
		i++;
	}
}

void		draw_call(t_point **p, t_point **save, int nb_line, char *name)
{
	t_wipa	pam;
	t_hook	hook;

	pam.mlx = mlx_init();
	pam.win = mlx_new_window(pam.mlx, WIDTH, HEIGTH, name);
	hook.pam = pam;
	hook.save = save;
	hook.px = 0;
	hook.py = 0;
	hook.color = 0x00ffffff;
	hook.vz = 1;
	hook.nb_line = nb_line;
	p = new_value(p, p, hook);
	hook.p = p;
	draw_it(p, nb_line, pam, 0x00ffffff);
	mlx_hook(pam.win, 2, (1L << 1), hook_fonct, &hook);
	mlx_loop(pam.mlx);
}
