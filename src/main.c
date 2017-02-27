/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 06:05:48 by opettex-          #+#    #+#             */
/*   Updated: 2016/07/01 17:21:37 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_map(t_env *e)
{
	char	*str;

	str = ft_itoa(e->i_max);
	if (e->what_fract == 'm')
		print_mandelbrot(e);
	else if (e->what_fract == 'j')
		print_julia(e);
	else if (e->what_fract == 'b')
		print_burning(e);
	else if (e->what_fract == 'c')
		print_celtique(e);
	mlx_string_put(e->mlx, e->win, 50, 50, 0xFFFFFF, str);
	free(str);
}

void	mlx_error(void)
{
	ft_putendl("mlx_error init");
	exit(1);
}

void	init_image(t_env *e)
{
	e->zoom = 100;
	e->x2 = -(W / 2);
	e->y2 = -(H / 2);
	e->i_max = 60;
	e->img = NULL;
	e->zi = 0;
	e->cr = 0.285;
	e->ci = 0.01;
}

int		check_error(int nb_ac, char *file)
{
	if (nb_ac != 2)
		return (1);
	if ((ft_strcmp(file, "Julia") && ft_strcmp(file, "julia")) &&
			(ft_strcmp(file, "Mandelbrot") && ft_strcmp(file, "mandelbrot"))
			&& (ft_strcmp(file, "Burning") && ft_strcmp(file, "burning"))
			&& (ft_strcmp(file, "Celtique") && ft_strcmp(file, "celtique")))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;

	init_image(&e);
	e.lock = 0;
	if (check_error(ac, av[1]))
	{
		ft_putendl("\"Julia\" \"Mandelbrot\" \"Celtique\" or \"Burning_Ship\"");
		return (1);
	}
	if (av[1][0] == 'j' || av[1][0] == 'J')
		e.what_fract = 'j';
	else if (av[1][0] == 'm' || av[1][0] == 'M')
		e.what_fract = 'm';
	else if (av[1][0] == 'b' || av[1][0] == 'B')
		e.what_fract = 'b';
	else if (av[1][0] == 'c' || av[1][0] == 'C')
		e.what_fract = 'c';
	init_mlx(&e);
	draw_map(&e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, (1L << 06), julia_distorsion, &e);
	mlx_hook(e.win, 2, (1L << 01), key_hook, &e);
	mlx_hook(e.win, 17, (1L << 17), red_exit, &e);
	mlx_loop(e.mlx);
	return (0);
}
