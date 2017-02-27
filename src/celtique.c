/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtique.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 19:02:57 by opettex-          #+#    #+#             */
/*   Updated: 2016/05/04 01:56:07 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			draw_celtique(t_env *e)
{
	double	zr_2;
	double	zi_2;
	double	tmp;
	int		i;

	i = -1;
	e->cr = e->x1 / e->zoom + e->x2 / e->zoom;
	e->ci = e->y1 / e->zoom + e->y2 / e->zoom;
	zr_2 = e->zr * e->zr;
	zi_2 = e->zi * e->zi;
	while ((zr_2 + zi_2) < 4 && ++i < e->i_max)
	{
		tmp = e->zr;
		e->zr = fabs(zr_2 - zi_2) + e->cr;
		e->zi = 2 * e->zi * tmp + e->ci;
		zr_2 = e->zr * e->zr;
		zi_2 = e->zi * e->zi;
	}
	return (i);
}

void		print_celtique(t_env *e)
{
	double	tmp_zi;
	int		i;

	new_image(e);
	e->y1 = -1;
	tmp_zi = e->zi;
	while (++e->y1 < H)
	{
		e->x1 = -1;
		while (++e->x1 < W)
		{
			e->zr = 0;
			e->zi = tmp_zi;
			i = draw_celtique(e);
			play_color(e, (e->x1 * 4 + e->y1 * W * 4), i);
		}
	}
	e->zi = tmp_zi;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
