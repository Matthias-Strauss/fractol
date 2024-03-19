/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/19 12:19:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prompt_user(void)
{
	pf_printf("################################\n");
	pf_printf("# INVALID PARAMETERS PROVIDED. #\n");
	pf_printf("################################\n\n");
	pf_printf("Options:\n");
	pf_printf("\"-m\" or \"--mandelbrot\":\n");
	pf_printf("Displays the Mandelbrot set fractal\n");
	pf_printf("\"-j\" or \"--julia\":\n");
	pf_printf("Displays the Julia set fractal\n");
	exit(1);
}

int	getrgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	function(mlx_key_data_t mkd, void *data)
{
	if (mkd.key == MLX_KEY_ESCAPE)
		exit(0);
	(void)data;
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	if (argc < 2)
		prompt_user();
	mlx = mlx_init(WIDTH, HEIGHT, "fractOOOOOOl", true);
	mlx_key_hook(mlx, function, NULL);
	while (1) // if camera verschoben, dann -> update bild
	{
		image = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_put_pixel(image, WIDTH / 2, HEIGHT / 2, getrgb(0, 255, 0, 255));
		mlx_image_to_window(mlx, image, 0, 0);
		mlx_loop(mlx);
		mlx_delete_image(mlx, image);
		usleep(1000);
	}
	return (0);
}
