/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:17 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/15 16:31:33 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

int	julia(t_fractol *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
 *	Comment ca fonctionne :
 *
 *	L'ensemble de Julia est un peu lie à l'ensemble de Mandelbrot :
 *	sa formule est identique. Ce qui est different, ce sont les nombres
 *	complexes que l'on insere.
 *
 *	Mandelbrot utilise 0 comme valeur de départ pour zr et zi et
 *	ajoute les coordonnées du pixel (cr et ci) à chaque itération.
 *
 *	Mais la fractal Julia commence avec les coordonnées du pixel comme
 * 	zr et zi et ajoute un autre nombre complexe (kr et ki) à chaque
 *	iteration.
 */
