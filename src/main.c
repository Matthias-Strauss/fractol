/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/03 21:36:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/// @brief initializes the fractol struct with default values
/// @param fractol Data struct
/// @param mlx MLX struct
/// @param img Image
void	init_fractol(t_fractol *fractol, mlx_t *mlx, mlx_image_t *img)
{
	fractol->img = img;
	fractol->mlx = mlx;
	fractol->math = (t_math *)malloc(sizeof(t_math));
	fractol->zoom = 1;
	fractol->w_width = WIDTH;
	fractol->w_height = HEIGHT;
	fractol->offset_x = -1.40117;
	fractol->offset_y = 0;
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fractol	fractol;

	if (argc < 2)
		prompt_user();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	// mlx_set_setting(MLX_MAXIMIZED, true);
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
	return (mlx_terminate(mlx), free(fractol.math), 0);
}
