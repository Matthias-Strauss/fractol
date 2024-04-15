/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:45:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/10 20:32:40 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_fractol *fractol)
{
	if (fractol->fractal_set == 1)
		mandelbrot(fractol->math, fractol);
	else if (fractol->fractal_set == 2)
		julia(fractol->math, fractol);
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
	pf_printf("|                                     |\n");
	pf_printf("| e.g. \"-j 0 0.35\"                     |\n");
	pf_printf("---------------------------------------\n\n");
	exit(1);
}

int	get_param(t_math *math, int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strncmp(argv[1], "-m", 2) || !ft_strncmp(argv[1], "--mandelbrot",
			12))
		return (fractol->fractal_set = 1, 1);
	if ((!ft_strncmp(argv[1], "-j", 2) || !ft_strncmp(argv[1], "--julia", 7))
		&& argc == 2)
	{
		math->ca = 0.355;
		math->cb = 0.355;
		return (fractol->fractal_set = 2, 2);
	}
	if ((ft_strncmp(argv[1], "-j", 2) || ft_strncmp(argv[1], "--julia", 7))
		&& argc == 4)
	{
		math->ca = ft_atof(argv[2]);
		math->cb = ft_atof(argv[3]);
		return (fractol->fractal_set = 2, 2);
	}
	else
		return (0);
}
