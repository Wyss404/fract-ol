/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:27 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/10 01:53:15 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	mandelbox(t_fractol *f, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * f->sx * ball_fold(f->rx, mag) + cr;
		vi = vi * f->sx * ball_fold(f->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
/*
	Comment ça fonctionne :

	Comme Mandelbrot, il est calculé en appliquant une formule
	répétitivement à chaque point de l'espace.
	
	L'équation de Mandelbrot est : z = z² + c
	
	L'équation de Mandelbox est : v = s * ballFold(r, f*boxFold(v)) + c
	où :
		- v est un nombre complexe de départ (les coordonnées de pixel traduites)
		- c est un nombre complexe inchangé (les coordonnées du pixel)
		- s est un multiplicateur d'échelle
		- r est un rayon minimum
		- f est un rayon fixe

	boxFold(v) signifie pour chaque axe a on a:

		si v[a] > 1 
    		v[a] =  2 - v[a]
		sinon si v[a] < -1
    		v[a] = -2 - v[a]

	ballFold(r, v) signifie que pour la magnitude m de v on a:

		si m < r
    		m = m/r²
		sinon si m < 1 
			m = 1/m²	
*/
