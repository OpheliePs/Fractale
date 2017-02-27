/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:00:24 by opettex-          #+#    #+#             */
/*   Updated: 2016/07/01 17:22:07 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			red_exit(void)
{
	exit(1);
	return (0);
}

void		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	if (!(e->win = mlx_new_window(e->mlx, H, W, "42 Fractol : opettex-")))
		mlx_error();
}

void		close_window(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}

void		new_image(t_env *e)
{
	if (e->img)
	{
		mlx_destroy_image(e->mlx, e->img);
		e->img = NULL;
	}
	if (!(e->img = mlx_new_image(e->mlx, W, H)))
		mlx_error();
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->end);
	if (e->data == NULL)
		mlx_error();
	e->bpp /= 8;
}

void		play_color(t_env *e, int k, int i)
{
	int		color_back;
	int		color_front;

	color_back = 0x0;
	color_front = 0xFF00FF;
	if (e->i_max == 0)
		e->i_max = 1;
	if (i == e->i_max)
		e->data[k] = color_back >> 2;
	else
	{
		e->data[k] = ((color_front / e->i_max) * i);
		e->data[++k] = ((color_front / e->i_max) * i) >> 6;
		e->data[++k] = ((color_front / e->i_max) * i) >> 12;
		e->data[++k] = ((color_front / e->i_max) * i) >> 16;
	}
}
