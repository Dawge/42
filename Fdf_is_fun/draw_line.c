/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:35:02 by rostroh           #+#    #+#             */
/*   Updated: 2017/03/19 18:15:13 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_wipa pam, int color)
{
	t_bres	ham;
	char	c;

	ham.dx = p2.x - p1.x >= 0 ? p2.x - p1.x : -(p2.x - p1.x);
	ham.dy = p2.y - p1.y >= 0 ? p2.y - p1.y : -(p2.y - p1.y);
	ham.sx = p1.x < p2.x ? 1 : -1;
	ham.sy = p1.y < p2.y ? 1 : -1;
	ham.err = (ham.dx > ham.dy ? ham.dx : -(ham.dy)) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(pam.mlx, pam.win, p1.x, p1.y, color);
		ham.e2 = ham.err;
		if (ham.e2 > -(ham.dx))
		{
			ham.err -= ham.dy;
			p1.x += ham.sx;
		}
		if (ham.e2 < ham.dy)
		{
			ham.err += ham.dx;
			p1.y += ham.sy;
		}
		c++;
	}
	mlx_pixel_put(pam.mlx, pam.win, p1.x, p1.y, color);
}
