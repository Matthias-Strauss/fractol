/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:07 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/05 15:29:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief calculates the pixels for the mandelbrot fractal and builds an image
/// 		and then renders it in the window.
/// @param math 	struct containing math vars specific to the fractal
/// @param fractol 	struct containing global vars
void	julia(t_math *math, t_fractol *fractol)
{
	uint32_t	color;

	math->x = -1;
	while (++(math->x) < fractol->w_width)
	{
		math->y = -1;
		while (++(math->y) < fractol->w_height)
		{
			if (fractol->w_height != fractol->img->height
				|| fractol->w_width != fractol->img->width)
			{
				mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
				return (redraw(fractol));
			}
			julia_subroutine(math, fractol);
			if (math->n == MAX_ITER)
				color = get_rgb(0, 0, 0, 255);
			else
				color = fractol->colors[math->n];
			mlx_put_pixel(fractol->img, math->x, math->y, color);
		}
	}
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

/// @brief Does the actual per pixel math for the mandelbrot fractal
/// @param math	struct containing math vars specific to the fractal
/// @param fractol 	struct containing global vars
void	julia_subroutine(t_math *math, t_fractol *fractol)
{
	math->a = (math->x - fractol->w_width / 2.0) * (4.0 / fractol->w_width)
		/ fractol->zoom + fractol->offset_x;
	math->b = (math->y - fractol->w_height / 2.0) * (4.0 / fractol->w_height)
		/ fractol->zoom + fractol->offset_y;
	while (++(math->n) < MAX_ITER)
	{
		math->aa = math->a * math->a;
		math->bb = math->b * math->b;
		if (math->aa + math->bb > 4)
			break ;
		math->ab = 2 * math->a * math->b;
		math->a = math->aa - math->bb + math->ca;
		math->b = math->ab + math->cb;
	}
}
