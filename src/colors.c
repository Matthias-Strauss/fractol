/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:21:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/27 18:49:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief Calculates all possible color values
/// @param fractol data struct
void	pre_calc_colors(t_fractol *fractol)
{
	uint32_t	i;
	uint32_t	j;
	double		t;

	i = 0;
	while (i <= fractol->iterations / 2)
	{
		t = (double)i / (fractol->iterations / 2);
		fractol->colors[i++] = get_rgb((int)(127.5 * (1.0 + sin(2.0 * M_PI * t
							/ 3.0))), (int)(127.5 * (1.0 + sin(2.0 * M_PI * t
							/ 3.0 + 2.0 * M_PI / 3.0))), (int)(127.5 * (1.0
						+ sin(2.0 * M_PI * t / 3.0 + 4.0 * M_PI / 3.0))), 200);
	}
	j = i - 1;
	while (i < fractol->iterations)
		fractol->colors[i++] = fractol->colors[j--];
}

/// @brief Calculates the RGBA value
/// @param r red value,   0 - 255
/// @param g green value, 0 - 255
/// @param b blue value,  0 - 255
/// @param a opacity,     0 - 255
/// @return RGBA value
int	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
