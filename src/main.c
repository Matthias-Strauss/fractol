/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/22 17:37:59 by mstrauss         ###   ########.fr       */
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

int	get_param(char **argv, t_fractol *fractol)
{
	if (ft_strncmp(argv[1], "-m", 2) || ft_strncmp(argv[1], "--mandelbrot", 12))
		fractol->fractal_set = 1;
	if (ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
		fractol->fractal_set = 2;
	if (ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
		// conditions fuer alternate julia hinzufuegen
		fractol->fractal_set = 3;
}

int	get_rgb(int r, int g, int b, int a)
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
	t_fractol	fractol;

	if (argc < 2)
		prompt_user();
	mlx = mlx_init(WIDTH, HEIGHT, "fractOOOOOOl", true);
	if (!mlx)
		return (EXIT_FAILURE);
	get_param(argv, &fractol);
	mlx_key_hook(mlx, function, NULL);
	while (1) // if camera verschoben, dann -> update bild
	{
		image = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_put_pixel(image, WIDTH / 2, HEIGHT / 2, getrgb(0, 255, 0, 255));
		mlx_image_to_window(mlx, image, 0, 0);
		mlx_scroll_hook(mlx);
		mlx_resize_hook(mlx_t * mlx, mlx_resizefunc func, void *param);
		mlx_loop(mlx);
		mlx_delete_image(mlx, image);
		usleep(1000);
	}
	return (0);
}

void	my_scroll_hook(void)
{
}

void	my_resize_hook(void)
{
}

void	my_key_hook(void)
{
}
