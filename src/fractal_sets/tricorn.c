/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:42 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/15 16:28:56 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = cr;
	zi = ci;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
	Comment ça fonctionne :

	Le fractal Tricorn (parfois appele Mandelbar) est une deformation
	de la fractal de Mandelbrot.

	Il utilise la meme formule sauf que la multiplication est différente.
	Dans Mandelbrot,	zi =  2 * zr * zi + ci
	Dans Tricorn,		zi = -2 * zr * zi + ci
							 ^
							 |
*/
