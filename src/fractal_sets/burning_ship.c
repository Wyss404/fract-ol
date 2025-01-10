/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:10 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/10 00:23:11 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* burning_ship :
 *	Vérifie si un nombre complexe fait partie de l'ensemble Burning Ship ou
 *	non. Prend en paramètres les coordonnées réelles et imaginaires d'un point,
 *	préalablement converties à partir des coordonnées d'un pixel.
 *	Retourne le nombre d'itérations avant que le nombre n'échappe 
 *	à l'ensemble Burning Ship, ce qui peut ensuite être utilisé
 *	pour déterminer la couleur.
 */
int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
	Comment ça fonctionne :

	Le fractal Burning Ship est une déformation du fractal
	de Mandelbrot. Il utilise la même équation pour calculer l'ensemble,
	mais utilise les valeurs absolues de zr et zi à chaque itération.
*/
