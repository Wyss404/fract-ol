/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:03 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/15 22:06:02 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	else if (f->set == TRICORN)
		nb_iter = tricorn(pr, pi);
	return (nb_iter);
}

/* render :
 *	Itère à travers chaque pixel de la fenêtre, traduit les coordonnées du
 *	pixel en un nombre complexe afin de pouvoir calculer si ce nombre fait
 *	partie de l'ensemble fractal ou non.
 *	Le nombre d'itérations que ce nombre complexe traverse avant d'être
 *	rejeté de l'ensemble fractal détermine quelle couleur sera appliquée au
 *	pixel. Une fois que tous les pixels ont été évalués et ajoutés à l'image
 *	MLX, cette fonction affiche l'image MLX dans la fenêtre.
 */

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
