/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:37:19 by opettex-          #+#    #+#             */
/*   Updated: 2016/05/19 18:33:29 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 27)
	{
		if (e->i_max > 1)
			e->i_max -= 10;
	}
	else if (keycode == 24)
		e->i_max += 10;
	else if (keycode == EXIT)
		close_window(e);
	else if (keycode == SPACE)
		init_image(e);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT
			|| keycode == RIGHT)
		move_key(keycode, e);
	else if (keycode == PLUS || keycode == MOINS || keycode == 13 || keycode == 0)
		key_zoom(keycode, e);
	else if (keycode == 83 || keycode == 84 || keycode == 85 
			|| keycode == 86 || keycode == 18 || keycode == 19 || keycode == 20
			|| keycode == 21)
		choose_fractol(keycode, e);
	else if (keycode == 32 || keycode == 37)
		lock_hook(keycode, e);
	new_image(e);
	mlx_clear_window(e->mlx, e->win);
	draw_map(e);
	return (0);
}

void	lock_hook(int keycode, t_env *e)
{
	if (keycode == 32)
		e->lock = 0;
	if (keycode == 37)
		e->lock = 1;
}

void	key_zoom(int keycode, t_env *e)
{
	if (keycode == PLUS || keycode == 13)
		e->zoom *= 1.1;
	if (keycode == MOINS || keycode == 0)
		e->zoom /= 1.1;
}

void	move_key(int keycode, t_env *e)
{
	if (keycode == UP)
		e->y2 += 80;
	if (keycode == DOWN)
		e->y2 -= 80;
	if (keycode == LEFT)
		e->x2 += 80;
	if (keycode == RIGHT)
		e->x2 -= 80;
}

void	choose_fractol(int keycode, t_env *e)
{
	init_image(e);
	if (keycode == 83 || keycode == 19)
		e->what_fract = 'm';
	if (keycode == 84 || keycode == 18)
		e->what_fract = 'j';
	if (keycode == 86 || keycode == 20)
		e->what_fract = 'b';
	if (keycode == 85 || keycode == 21)
		e->what_fract = 'c';
}
