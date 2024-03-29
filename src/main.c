/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/29 13:44:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prompt_user(void)
{
	pf_printf("\033[0;36m\n  ░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒\
░▒▓██████▓▒░░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░\
▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░\
▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░\
▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░\
▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░\
▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \n\033[0m");
	pf_printf("\033[0;36m  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░   \
░▒▓██████▓▒░░▒▓████████▓▒░ \033[0m \033[0;35mby @mstrauss\n\n\033[0m");
	// pf_printf("\n#######################################\n");
	pf_printf("  !!! INVALID PARAMETERS PROVIDED !!!  \n\n");
	// pf_printf("#######################################\n\n");
	pf_printf("OPTIONS:\n");
	pf_printf("---------------------------------------\n");
	pf_printf("| \"-m\" or \"--mandelbrot\":             |\n");
	pf_printf("| Displays the Mandelbrot set fractal |\n");
	pf_printf("|                                     |\n");
	pf_printf("| \"-j\" or \"--julia\":                  |\n");
	pf_printf("| Displays the Julia set fractal      |\n");
	pf_printf("---------------------------------------\n\n");
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

void	init_fractol(t_fractol *fractol, mlx_t *mlx, mlx_image_t *img)
{
	fractol->img = img;
	fractol->mlx = mlx;
	fractol->math = (t_math *)malloc(sizeof(t_math));
	fractol->zoom = 1;
	fractol->w_width = WIDTH;
	fractol->w_height = HEIGHT;
	fractol->offset_x = -0.5;
	fractol->offset_y = 0;
}

void	my_key_func(mlx_key_data_t mkd, void *data)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)data;
	if (mkd.key == MLX_KEY_ESCAPE)
		exit(-1);
	(void)data;
}

void	my_scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)param;
	if (ydelta > 0)
		fractol->zoom += ydelta; // Adjust ydelta for zoom speed
	if (ydelta < 0)
		fractol->zoom += ydelta;
	if (fractol->fractal_set == 1)
		mandelbrot(fractol->math, fractol);
	else if (fractol->fractal_set == 2)
		julia(fractol->math, fractol);
	else if (fractol->fractal_set == 3)
		alternate_julia(fractol->math, fractol);
}

void	my_resize_func(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->w_width = width;
	fractol->w_height = height;
	redraw(fractol);
}

void	redraw(t_fractol *fractol)
{
	mlx_delete_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, fractol->w_width,
			fractol->w_height);
	if (fractol->fractal_set == 1)
		mandelbrot(fractol->math, fractol);
	else if (fractol->fractal_set == 2)
		julia(fractol->math, fractol);
	else if (fractol->fractal_set == 3)
		alternate_julia(fractol->math, fractol);
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
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image == NULL)
		return (EXIT_FAILURE);
	init_fractol(&fractol, mlx, image);
	get_param(argv, &fractol);
	mlx_key_hook(mlx, my_key_func, NULL);
	mlx_scroll_hook(mlx, my_scroll_func, &fractol);
	mlx_resize_hook(mlx, my_resize_func, &fractol);
	redraw(&fractol);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	usleep(1000);
	return (mlx_terminate(mlx), 0);
}
