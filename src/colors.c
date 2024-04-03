/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:21:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/03 19:42:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief Calculates all possible color values
/// @param fractol data struct
void	pre_calc_colors(t_fractol *fractol)
{
	int		n;
	float	hue;

	n = 0;
	while (n <= MAX_ITER)
	{
		fractol->colors[n] = hsl_to_rgb(((float)n / MAX_ITER) * 360, 1.0, 0.5);
		n++;
	}
}

/// @brief Converts HSL color space to RGB color space
/// @param h Hue, a value between 0 and 360
/// @param s Saturation, a value between 0 and 1
/// @param l Lightness, a value between 0 and 1
/// @return RGB color
int	hsl_to_rgb(float h, float s, float l)
{
	float	q;
	float	p;
	float	r;
	float	g;
	float	b;

	if (s == 0)
	{
		r = l;
		g = l;
		b = l;
	}
	else
	{
		q = l < 0.5 ? l * (1 + s) : l + s - l * s;
		p = 2 * l - q;
		r = hue_to_rgb(p, q, h + 1 / 3.0);
		g = hue_to_rgb(p, q, h);
		b = hue_to_rgb(p, q, h - 1 / 3.0);
	}
	return ((int)(r * 255) << 24 | (int)(g * 255) << 16 | (int)(b
			* 255) << 8 | 255);
}

/// @brief Helper function for HSL to RGB conversion
/// @param p, q, t float values
/// @return float value
float	hue_to_rgb(float p, float q, float t)
{
	if (t < 0)
		t += 1;
	if (t > 1)
		t -= 1;
	if (t < 1 / 6.0)
		return (p + (q - p) * 6 * t);
	if (t < 1 / 2.0)
		return (q);
	if (t < 2 / 3.0)
		return (p + (q - p) * (2 / 3.0 - t) * 6);
	return (p);
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
