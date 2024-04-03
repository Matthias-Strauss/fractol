/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:45:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/03 21:37:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_fractol *fractol)
{
	// int	black;
	// black = get_rgb(255, 255, 255, 0);
	// mlx_delete_image(fractol->mlx, fractol->img);
	// fractol->img = mlx_new_image(fractol->mlx, fractol->w_width,
	// 		fractol->w_height);
	// memset(fractol->img->pixels, black, fractol->img->width
	// 	* fractol->img->height * sizeof(int32_t));
	if (fractol->fractal_set == 1)
		mandelbrot(fractol->math, fractol);
	else if (fractol->fractal_set == 2)
		julia(fractol->math, fractol);
	// else if (fractol->fractal_set == 3)
	// 	alternate_julia(fractol->math, fractol);
}

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
	pf_printf("  !!! INVALID PARAMETERS PROVIDED !!!  \n\n");
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
	// if (ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
	// 	// conditions fuer alternate julia hinzufuegen
	// 	return (fractol->fractal_set = 3, 3);
	else
		return (0);
}
