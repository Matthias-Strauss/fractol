/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:21:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/14 18:33:52 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief Calculates all possible color values
/// @param fractol data struct
void	pre_calc_colors(t_fractol *fractol)
{
	uint32_t	n;

	fractol->colors[0] = 4278190080;
	fractol->colors[1] = 4278190080;
	n = 2;
	while (n <= MAX_COLORS)
	{
		fractol->colors[n] = get_rgb(255 / MAX_COLORS * n, 100, 255 - (255
					/ MAX_COLORS * n), 255);
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
