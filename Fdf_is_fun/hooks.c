/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:12:35 by rostroh           #+#    #+#             */
/*   Updated: 2017/03/20 16:54:16 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int value)
{
	if (value == 15)
		return (0x00ff0000);
	else if (value == 5)
		return (0x0000ff00);
	else if (value == 11)
		return (0x000000ff);
	else
		return (0x00ffffff);
}

int		loop_hook(int keycode, t_hook *ptr)
{
	if (keycode == 78 || keycode == 69)
	{
		if (keycode == 78)
			ptr->vz--;
		if (keycode == 69)
			ptr->vz++;
		ptr->p = new_value(ptr->p, ptr->save, *ptr);
		mlx_clear_window(ptr->pam.mlx, ptr->pam.win);
		draw_it(ptr->p, ptr->nb_line, ptr->pam, ptr->color);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (keycode == 123)
			ptr->px--;
		if (keycode == 124)
			ptr->px++;
		if (keycode == 125)
			ptr->py++;
		if (keycode == 126)
			ptr->py--;
		ptr->p = new_value(ptr->p, ptr->save, *ptr);
		mlx_clear_window(ptr->pam.mlx, ptr->pam.win);
		draw_it(ptr->p, ptr->nb_line, ptr->pam, ptr->color);
	}
	return (0);
}

int		hook_fonct(int keycode, void *param)
{
	t_hook	*ptr;

	ptr = (t_hook *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->pam.mlx, ptr->pam.win);
		exit(-1);
	}
	loop_hook(keycode, ptr);
	if (keycode == 15 || keycode == 5 || keycode == 11)
	{
		ptr->color = get_color(keycode);
		draw_it(ptr->p, ptr->nb_line, ptr->pam, ptr->color);
	}
	return (0);
}
