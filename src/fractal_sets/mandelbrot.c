/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:42:34 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/21 21:30:42 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot :
 *   Verifie si un nombre complexe fait partie de l'ensemble de Mandelbrot
 *   ou non. Prend en parametres les coordonnees reelles et imaginaires
 *   d'un point, prealablement converties a partir des coordonnees d'un pixel.
 *   Retourne le nombre d'iterations avant que le nombre n'echappe
 *   a l'ensemble de Mandelbrot, ce qui peut ensuite etre utilise
 *   pour déterminer la couleur.
 */

int	mandelbrot(double cr, double ci)
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
		if ((zr * zr + zi * zi) > 4)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
/*
    Comment ca fonctionne :

    La formule de Mandelbrot itere sur des nombres complexes :
    À chaque iteration, Z est mis au carre.
        Z = Z * Z + c
    
    Si le resultat tend vers l'infini, cela signifie qu'il ne fait pas partie
    de l'ensemble. Si le resultat reste petit apres plusieurs iterations,
    le nombre fait partie de l'ensemble.

    Exemples avec des nombres reguliers :
        ex. : c = 1
            Z =  0
            Z =  0 *  0 + 1 = 1
            Z =  1 *  1 + 1 = 2
            Z =  2 *  2 + 1 = 5
            Z =  5 *  5 + 1 = 26
            Z = 26 * 26 + 1 = 677
            ... Croit vers l'infini.
            Donc 1 ne fait PAS partie de l'ensemble de Mandelbrot.
    
        ex.2 : c = -1
            Z =    0
            Z =    0 *    0 + (-1) = -1
            Z = (-1) * (-1) + (-1) =  0
            Z =    0 *    0 + (-1) = -1
            ... Le résultat oscille entre -1 et 0
            Donc -1 fait partie de l'ensemble de Mandelbrot car il ne tend
            pas vers l'infini.

    Ici, nous ne pouvons pas calculer jusqu'a l'infini, mais il est sûr de
    dire que si la valeur absolue de Z depasse 2 elle tendra vers l'infini
    et le nombre ne fera pas partie de l'ensemble de Mandelbrot.

    Comme nous travaillons avec des nombres complexes nous devons calculer la
    partie réelle Zr et la partie imaginaire Zi et les evaluer ensemble.
    La multiplication de deux nombres complexes se fait comme ca :
    (a + bi)²   = (a + bi) * (a + bi)
                = (a * a) + (a * bi) + (a * bi) + (bi * bi)
                = (a * a) - (bi * bi) + 2 * (a * bi)  <--- voir rappel|
           soit = a² - b² + 2 * a * b                 <---------------|
    Donc la formule de multiplication pour la partie imaginaire est :
                    (a * a) - (bi * bi)
    Et la formule de multiplication pour la partie reelle est :
                    2 * a * bi

    Rappel : i² = -1 soit (bi * bi) = b²i² soit b² * -1 donc -b²
*/
