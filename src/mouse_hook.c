/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:04:11 by opettex-          #+#    #+#             */
/*   Updated: 2016/05/19 18:31:02 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	x = 0;
	if (y > 0)
	{
		if (button == SCROLL_UP || button == 1)
		{
			e->x0 = (x / e->zoom) + e->x1;
			e->y0 = (y / e->zoom) + e->y1;
			e->zoom *= 1.1;
			e->x1 = e->x0 - (x / e->zoom);
			e->y1 = e->y0 - (y / e->zoom);
		}
		if (button == SCROLL_DOWN || button == 2)
		{
			e->x0 = (x / e->zoom) + e->x1;
			e->y0 = (y / e->zoom) + e->y1;
			e->zoom /= 1.1;
			e->x1 = e->x0 - (x / e->zoom);
			e->y1 = e->y0 - (y / e->zoom);
		}
		new_image(e);
		mlx_clear_window(e->mlx, e->win);
		draw_map(e);
	}
	return (0);
}

int		julia_distorsion(int x, int y, t_env *e)
{
	if (e->what_fract == 'j' && e->lock == 0)
	{
		e->cr += ((x - (W / 2)) - (y - (H / 2))) * 0.0001;
		e->ci -= ((y - (H / 2)) - (x - (W / 2))) * 0.0001;
		new_image(e);
		mlx_clear_window(e->mlx, e->win);
		draw_map(e);
	}
	return (0);
}
