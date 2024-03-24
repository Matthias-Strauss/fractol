/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:31:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/24 15:33:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	math(t_math *math)
{
	math->x = 0;
	math->y = 0;
	while (math->x < WIDTH)
	{
		while (math->y < HEIGHT)
		{
			a = ? ;
			b = ? ;
			n = 0;
			while (n < 100)
			{
				aa = a * a - b * b;
				bb = 2 * a * b;
			}
			y++;
		}
		x++;
	}
}
