/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 19:05:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

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
