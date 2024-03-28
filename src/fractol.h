/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:51 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/28 15:42:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------------------------------------------------------- */
/*                          FRACTOL HEADER DEFINITION                         */
/* -------------------------------------------------------------------------- */
#ifndef FRACTOL_H
# define FRACTOL_H

/* ----------------------------- header includes ---------------------------- */
# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/* ------------------------------ window width ------------------------------ */
# ifndef WIDTH
#  define WIDTH 1920
# endif

/* ------------------------------ window height ----------------------------- */
# ifndef HEIGHT
#  define HEIGHT 1080
# endif

/* ------------------------------ max iterations ---------------------------- */
# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

/* ----------------------- fractal set math variables ----------------------- */
typedef struct s_math
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	double		ab;
	int			n;
	int			x;
	int			y;
}				t_math;

/* -------------------------------------------------------------------------- */
/*                            data struct typedef                             */
/* -------------------------------------------------------------------------- */
typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_math		*math;
	double		zoom;
	double		w_width;
	double		w_height;
	double		offset_x;
	double		offset_y;
	int			fractal_set;

}				t_fractol;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

int				get_param(char **argv, t_fractol *fractol);
int				get_rgb(int r, int g, int b, int a);
void			init_fractol(t_fractol *fractol, mlx_t *mlx, mlx_image_t *img);
void			prompt_user(void);
void			my_exit_func(mlx_key_data_t mkd, void *data);
void			math(t_math *math, t_fractol *fractol);
void			my_scroll_func(double xdelta, double ydelta, void *param);
void			my_resize_func(int32_t width, int32_t height, void *param);
void			my_key_func(mlx_key_data_t mkd, void *data);

/* -------------------------- mandelbrot functions -------------------------- */
void			mandelbrot(t_math *math, t_fractol *fractol);
void			mandelbrot_subroutine(t_math *math, t_fractol *fractol);

/* ----------------------------- julia functions ---------------------------- */
void			julia(t_math *math, t_fractol *fractol);

/* ------------------------- third fractal functions ------------------------ */
void			alternate_julia(t_math *math, t_fractol *fractol);
#endif