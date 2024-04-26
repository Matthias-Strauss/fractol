/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:18 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/26 16:18:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_key_func(mlx_key_data_t mkd, void *data)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)data;
	if (mkd.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		usleep(1000);
		mlx_terminate(fractol->mlx);
		free(fractol->math);
		exit(EXIT_SUCCESS);
	}
	if (mkd.key == MLX_KEY_UP && fractol->iterations < MAX_ITER - 2)
	{
		fractol->iterations += 2;
		pre_calc_colors(fractol);
		redraw(fractol);
	}
	if (mkd.key == MLX_KEY_DOWN && fractol->iterations > 3)
	{
		fractol->iterations -= 2;
		pre_calc_colors(fractol);
		redraw(fractol);
	}
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)param;
	if (ydelta > 0)
		fractol->zoom *= 1.1;
	if (ydelta < 0)
		fractol->zoom *= 0.9;
	redraw(fractol);
}

void	my_resize_func(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->w_width = width;
	fractol->w_height = height;
	redraw(fractol);
}
