/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:17 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/10 01:55:08 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* julia_shift :
 *	Change les valeurs de kr et ki pour le calcul de Julia afin d'obtenir
 *	une forme différente du fractal de Julia. Cette fonction est
 *	appelée lorsque l'utilisateur clique sur un point à l'écran.
 */

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

/* julia :
 *	Vérifie si un nombre complexe fait partie de l'ensemble de Julia ou non.
 *	Prend en paramètres les coordonnées réelles et imaginaires d'un point,
 *	préalablement converties à partir des coordonnées d'un pixel.
 *	Retourne le nombre d'itérations avant que le nombre n'échappe 
 *	à l'ensemble de Julia, ce qui peut ensuite être utilisé pour déterminer
 *	la couleur.
 */
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
 *	Comment ça fonctionne :
 *
 *	L'ensemble de Julia est étroitement lié à l'ensemble de Mandelbrot :
 *	sa formule est identique. Ce qui diffère, ce sont les nombres
 *	complexes que l'on y insère.
 *
 *	Mandelbrot utilise 0 comme valeur de départ pour zr et zi, et
 *	ajoute les coordonnées du pixel (cr et ci) à chaque itération.
 *
 *	En revanche, Julia commence avec les coordonnées du pixel comme
 * 	zr et zi et ajoute un autre nombre complexe (kr et ki) à chaque
 *	itération.
 *
 *	Les valeurs de kr et ki déterminent la forme que prendra Julia.
 * 	Si kr + ki fait partie de l'ensemble de Mandelbrot, Julia sera une
 *	forme continûment solide. Si kr + ki ne fait pas partie de l'ensemble
 *	de Mandelbrot, le fractal de Julia sera un ensemble déconnecté
 *	d'îles séparées. Si kr + ki est un point proche de la frontière du
 * 	fractal de Mandelbrot, les mêmes motifs que nous voyons à ce point
 *	dans le fractal de Mandelbrot émergeront dans le fractal de Julia.
*/
