/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_striped.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:41:59 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/10 01:52:05 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_color_stripe(t_fractol *f, int color, int skip)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		f->palette[i] = color;
		i += skip;
	}
}

/* get_percent_color :
 *	Calcule une couleur qui est à un certain pourcentage
 *	éloignée de la couleur fournie. Chaque canal de couleur doit être
 *	calculé séparément. Conçu pour trouver des couleurs quelque peu
 *	complémentaires. (Pour des couleurs véritablement complémentaires choisies
 *	sur le cercle chromatique,cette fonction devrait être radicalement
 *	modifiée pour utiliser les couleurs HSL plutôt que RGB...)
 *	Remarque : rgb[3] : rgb[0] = rouge, rgb[1] = vert, rgb[2] = bleu
 */
int	get_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

/* set_color_zebra :
 *	Applique un schéma de couleurs en rayures zébrées. Les couleurs
 *	alternent entre la couleur donnée et une couleur complémentaire
 *	située à 50 % de la première.
 */
void	set_color_zebra(t_fractol *f, int color)
{
	int	color2;

	color2 = get_percent_color(color, 50);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, color2, 2);
	f->palette[MAX_ITERATIONS - 1] = 0;
}

/* set_color_triad :
*	Applique un schéma de couleurs en bandes. Les couleurs alternent entre
*	trois couleurs : la couleur donnée, une couleur située à 33 % de la première
*	et une couleur située à 66 % de la première.
*/
void	set_color_triad(t_fractol *f, int color)
{
	int		triad[2];

	triad[0] = get_percent_color(color, 33);
	triad[1] = get_percent_color(color, 66);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, triad[0], 2);
	fill_color_stripe(f, triad[1], 3);
	f->palette[MAX_ITERATIONS - 1] = 0;
}

/* set_color_tetra :
 *	Applique un schéma de couleurs en bandes. Les couleurs alternent entre
 *	quatre couleurs : la couleur donnée, une couleur située à 25 % de celle-ci,
 *	une couleur située à 50 % de la première, et une couleur située à 75 % de
 *	la première.
 */
void	set_color_tetra(t_fractol *f, int color)
{
	int	tetra[3];

	tetra[0] = get_percent_color(color, 25);
	tetra[1] = get_percent_color(color, 50);
	tetra[2] = get_percent_color(color, 75);
	fill_color_stripe(f, color, 1);
	fill_color_stripe(f, tetra[0], 2);
	fill_color_stripe(f, tetra[1], 3);
	fill_color_stripe(f, tetra[2], 4);
	f->palette[MAX_ITERATIONS - 1] = 0;
}
