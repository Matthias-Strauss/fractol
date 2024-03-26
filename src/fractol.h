/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:51 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/26 16:22:25 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	double		zoom;
	double		w_width;
	double		w_height;
	double		offsetX;
	double		offsetY;
	int			fractal_set;

}				t_fractol;

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

void			prompt_user(void);
int				get_param(char **argv, t_fractol *fractol);
int				get_rgb(int r, int g, int b, int a);
void			function(mlx_key_data_t mkd, void *data);
void			math(t_math *math, t_fractol *fractol);
void			my_scroll_func(void);
void			my_resize_func(void);
void			my_key_func(void);

#endif