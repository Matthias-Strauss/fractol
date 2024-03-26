/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/26 14:32:49 by mstrauss         ###   ########.fr       */
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
		return (fractol->fractal_set = 1, 1);
	if (ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
		return (fractol->fractal_set = 2, 2);
	if (ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
		// conditions fuer alternate julia hinzufuegen
		return (fractol->fractal_set = 3, 3);
	else
		return (0);
}

int	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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
	init_fractol(&fractol);
	mlx_key_hook(mlx, function, NULL);
	while (1) // if camera verschoben, dann -> update bild
	{
		image = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (image == NULL)
			return (EXIT_FAILURE);
		mlx_put_pixel(image, WIDTH / 2, HEIGHT / 2, get_rgb(0, 255, 0, 255));
		mlx_image_to_window(mlx, image, 0, 0);
		mlx_scroll_hook(mlx, my_scroll_func, NULL);
		// mlx_mouse_hook(mlx, my_mouse_func, NULL);
		mlx_resize_hook(mlx, my_resize_func, NULL);
		mlx_loop(mlx);
		mlx_delete_image(mlx, image);
		usleep(1000);
	}
	return (mlx_terminate(mlx), 0);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->w_width = WIDTH;
	fractol->w_height = HEIGHT;
	fractol->offsetX = -0.5;
	fractol->offsetY = 0;
}
void	function(mlx_key_data_t mkd, void *data)
{
	if (mkd.key == MLX_KEY_ESCAPE)
		exit(-1);
	(void)data;
}

void	my_scroll_func(t_fractol *fractol, mlx_key_data_t *mkd)
{
	if (mkd->key == 4)
		fractol->zoom *= 1.05;
	else if (mkd->key == 5)
		fractol->zoom /= 1.05;
}

void	my_resize_func(void)
{
}

void	my_key_func(void)
{
}
