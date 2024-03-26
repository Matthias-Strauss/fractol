/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:31:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/26 16:23:49 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_math *math, t_fractol *fractol)
{
	int	color;

	math->x = -1;
	math->y = -1;
	math->ca = math->x;
	math->cb = math->y;
	while (++(math->x) <= fractol->w_width)
	{
		while (++(math->y) <= fractol->w_height)
		{
			mandelbrot_subroutine(math, fractol);
			if (math->n >= MAX_ITER)
				color = get_rgb(0, 0, 0, 0);
			else
				color = get_rgb(0, 255, 0, math->n * 255 / MAX_ITER);
			mlx_put_pixel(fractol->img, math->x, math->y, color);
		}
	}
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

void	mandelbrot_subroutine(t_math *math, t_fractol *fractol)
{
	math->a = (math->x - fractol->w_width / 2.0) * (4.0 / fractol->w_width)
		/ fractol->zoom + fractol->offsetX;
	math->b = (math->y - fractol->w_height / 2.0) * (4.0 / fractol->w_height)
		/ fractol->zoom + fractol->offsetY;
	math->n = 0;
	while (math->n++ < MAX_ITER)
	{
		math->aa = math->a * math->a - math->b * math->b;
		math->bb = 2 * math->a * math->b;
		math->a = math->aa + math->ca;
		math->b = math->bb + math->cb;
		if (math->a * math->a + math->b * math->b > 16)
			break ;
	}
}
