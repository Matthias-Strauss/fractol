/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:31:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/27 18:42:11 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief calculates the pixels for the mandelbrot fractal and builds an image
/// 		and then renders it in the window.
/// @param math 	struct containing math vars specific to the fractal
/// @param fractol 	struct containing global vars
void	mandelbrot(t_math *math, t_fractol *fractol)
{
	math->x = -1;
	while (++(math->x) < fractol->w_width)
	{
		math->y = -1;
		while (++(math->y) < fractol->w_height)
		{
			math->a = (math->x - fractol->w_width / 2.0) * (4.0
					/ fractol->w_width) / fractol->zoom + fractol->offset_x;
			math->b = (math->y - fractol->w_height / 2.0) * (4.0
					/ fractol->w_height) / fractol->zoom + fractol->offset_y;
			math->ca = math->a;
			math->cb = math->b;
			mandelbrot_subroutine(math, fractol);
			if (math->n >= fractol->iterations)
				mlx_put_pixel(fractol->img, math->x, math->y, get_rgb(0, 0, 0,
						255));
			else
				mlx_put_pixel(fractol->img, math->x, math->y,
					fractol->colors[(math->n + fractol->c_offs)
					% fractol->iterations]);
		}
	}
}

/// @brief Does the actual per pixel math for the mandelbrot fractal
/// @param math	struct containing math vars specific to the fractal
/// @param fractol 	struct containing global vars
inline void	mandelbrot_subroutine(t_math *math, t_fractol *fractol)
{
	if (math->a * math->a + math->b * math->b > 4)
		return ;
	math->n = 0;
	math->prev_a = 0;
	math->prev_b = 0;
	while (math->n < fractol->iterations)
	{
		math->aa = math->a * math->a - math->b * math->b;
		math->bb = 2 * math->a * math->b;
		math->a = math->aa + math->ca;
		math->b = math->bb + math->cb;
		if (math->a * math->a + math->b * math->b > 4)
			break ;
		if (math->a == math->prev_a && math->b == math->prev_b)
		{
			math->n = fractol->iterations;
			break ;
		}
		math->prev_a = math->a;
		math->prev_b = math->b;
		math->n++;
	}
}
