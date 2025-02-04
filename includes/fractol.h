/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:02:20 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/22 22:28:58 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 700
# define MAX_ITERATIONS 50

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;

/*  Fractal Sets   */
int		mandelbrot(double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
int		burning_ship(double cr, double ci);
int		tricorn(double cr, double ci);

/*  Draw Fractal	*/
void	render(t_fractol *f);
int		julia_shift(int x, int y, t_fractol *f);

/* Colors	*/
void	color_shift(t_fractol *f);
void	set_color_triad(t_fractol *f, int color);
void	set_color_tetra(t_fractol *f, int color);
void	set_color_opposites(t_fractol *f, int color);
void	set_color_contrasted(t_fractol *f, int color);
void	set_color_graphic(t_fractol *f, int color);
void	set_color_mono(t_fractol *f, int color);
int		get_percent_color(int color, double percent);

/*  Events   */
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

/* Initialization */
void	clean_init(t_fractol *f);
void	reinit_img(t_fractol *f);
void	init(t_fractol *f);
void	get_complex_layout(t_fractol *f);
void	get_color(t_fractol *f, int ac, char **av);
double	ft_atof(char *str);

/*  Utils   */
int		end_fractol(t_fractol *mlx);
void	clean_exit(int error_code, t_fractol *f);
int		msg(char *str1, char *str2, int errno);
void	help_msg(t_fractol *f);
void	print_controls(void);
int		ft_atox_color(t_fractol *f, char *color);

#endif
