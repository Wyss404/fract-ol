/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:02 by hdruel            #+#    #+#             */
/*   Updated: 2025/01/15 15:10:31 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_2(t_fractol *f)
{
	if (f->color_pattern == 0)
		set_color_zebra(f, f->color);
	else if (f->color_pattern == 1)
		set_color_triad(f, f->color);
	else if (f->color_pattern == 2)
		set_color_tetra(f, f->color);
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
