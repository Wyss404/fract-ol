/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:42 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/10 01:52:44 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* tricorn :
 *	Vérifie si un nombre complexe fait partie de l'ensemble Tricorn ou non.
 *	Prend en paramètres les coordonnées réelles et imaginaires d'un point,
 *	préalablement converties à partir des coordonnées d'un pixel.
 *	Retourne le nombre d'itérations avant que le nombre n'échappe 
 *	à l'ensemble Tricorn, ce qui peut ensuite être utilisé pour déterminer
 *	la couleur.
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
	Comment ça fonctionne :

	Le fractal Tricorn (parfois appelé Mandelbar) est une déformation
	du fractal de Mandelbrot.

	Il utilise la même formule de base, sauf que la multiplication diffère.
	Dans Mandelbrot,	zi =  2 * zr * zi + ci
	Dans Tricorn,		zi = -2 * zr * zi + ci
							 ^
							 |
*/
