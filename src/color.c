/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:02 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/22 21:49:51 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_2(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_triad(f, alt_color);
	else if (f->color_pattern == 2)
		set_color_tetra(f, alt_color);
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 5;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 3)
		set_color_contrasted(f, alt_color);
	else if (f->color_pattern == 4)
		set_color_graphic(f, alt_color);
	else
		color_shift_2(f);
}

void	get_color(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && ac == 5)
		f->color = ft_atox_color(f, av[4]);
	else if (f->set != JULIA && ac == 3)
		f->color = ft_atox_color(f, av[2]);
	if (ac == 2 || (f->set == JULIA && ac == 4))
		f->color = 0x7F33DD;
}
