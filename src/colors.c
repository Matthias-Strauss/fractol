/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:21:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/05 15:38:47 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief Calculates all possible color values
/// @param fractol data struct
void	pre_calc_colors(t_fractol *fractol)
{
	int	n;

	n = 0;
	while (n <= MAX_ITER)
	{
		fractol->colors[n] = get_rgb(255 / MAX_ITER * n, 100, 255 - (255
					/ MAX_ITER * n), 255);
		n++;
	}
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
