/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:55:21 by opettex-          #+#    #+#             */
/*   Updated: 2016/07/01 17:20:20 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# define H 900
# define W 900
# define EXIT 53
# define SPACE 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MOINS 78
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct		s_env
{
	int				x;
	int				y;
	void			*win;
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				color;
	int				end;
	char			what_fract;
	int				zoom;
	int				i_max;
	int				lock;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			x0;
	double			y0;

}					t_env;

int					red_exit(void);
void				mlx_error(void);
void				init_image(t_env *e);
int					check_error(int nb_ac, char *file);
void				init_mlx(t_env *e);
void				close_window(t_env *e);
void				new_image(t_env *e);
void				print_image(t_env *e);
void				print_map(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
void				key_zoom(int keycode, t_env *e);
void				move_key(int keycode, t_env *e);
void				lock_hook(int keycode, t_env *e);
void				draw_map(t_env *e);
void				print_mandelbrot(t_env *e);
void				play_color(t_env *e, int k, int i);
void				print_julia(t_env *e);
void				print_burning(t_env *e);
void				print_celtique(t_env *e);
void				choose_fractol(int keycode, t_env *e);
int					julia_distorsion(int x, int y, t_env *e);
#endif
