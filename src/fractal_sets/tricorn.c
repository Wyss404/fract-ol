/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:42 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/07 17:42:43 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* tricorn:
*	Checks whether a complex number is part of the Tricorn set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Tricorn set, which can then be used to determine coloring.
*/
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
	How it works:

	The Tricorn fractal (sometimes called the Mandelbar) is a distortion
	of the Mandelbrot fractal.

	It uses the same basic formula, except the multiplication differs.
	In Mandelbrot,	zi =  2 * zr * zi + ci
	In Tricorn,		zi = -2 * zr * zi + ci
*/
