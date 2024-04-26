/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:51 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/26 19:19:34 by mstrauss         ###   ########.fr       */
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

/* ----------------------------- Bytes Per Pixel ---------------------------- */

// # ifndef DEBUG
// #  define DEBUG 1
// # endif

/* ------------------------------ window width ------------------------------ */

# ifndef WIDTH
#  define WIDTH 800
# endif

/* ------------------------------ window height ----------------------------- */

# ifndef HEIGHT
#  define HEIGHT 800
# endif

/* ------------------------------ max iterations ---------------------------- */

# ifndef MAX_ITER
#  define MAX_ITER 1000
# endif

/* -------------------------------- max colors ------------------------------ */

# ifndef MAX_COLORS
#  define MAX_COLORS 100
# endif

/* ----------------------- fractal set math variables ----------------------- */

typedef struct s_math
{
	float		a;
	float		b;
	float		prev_a;
	float		prev_b;
	float		ca;
	float		cb;
	float		aa;
	float		bb;
	float		ab;
	uint32_t	n;
	uint32_t	x;
	uint32_t	y;
}				t_math;

/* -------------------------------------------------------------------------- */
/*                            data struct typedef                             */
/* -------------------------------------------------------------------------- */

typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_math		*math;
	uint32_t	argc;
	uint32_t	colors[MAX_ITER];
	uint32_t	iterations;
	float		zoom;
	float		w_width;
	float		w_height;
	float		offset_x;
	float		offset_y;
	float		ca;
	float		cb;
	int			fractal_set;
}				t_fractol;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

int				get_param(t_math *math, int argc, char **argv,
					t_fractol *fractol);
void			pre_calc_colors(t_fractol *fractol);
int				get_rgb(int r, int g, int b, int a);
void			init_fractol(t_fractol *fractol, mlx_t *mlx, mlx_image_t *img,
					char **argv);
void			prompt_user(void);
void			my_exit_func(mlx_key_data_t mkd, void *data);
void			math(t_math *math, t_fractol *fractol);
void			my_scroll_func(double xdelta, double ydelta, void *param);
void			my_resize_func(int32_t width, int32_t height, void *param);
void			my_key_func(mlx_key_data_t mkd, void *data);
void			redraw(t_fractol *fractol);

/* -------------------------- mandelbrot functions -------------------------- */

void			mandelbrot(t_math *math, t_fractol *fractol);
void			mandelbrot_subroutine(t_math *math, t_fractol *fractol);

/* ----------------------------- julia functions ---------------------------- */

void			julia(t_math *math, t_fractol *fractol);
void			julia_subroutine(t_math *math, t_fractol *fractol);

/* ------------------------- burning ship functions ------------------------- */
void			burning_ship(t_math *math, t_fractol *fractol);
void			burning_ship_subroutine(t_math *math, t_fractol *fractol);

#endif