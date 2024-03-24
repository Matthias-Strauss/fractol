/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:51 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/22 17:31:23 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef WIDTH
#  define WIDTH 1920
# endif

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"

typedef struct s_fractol
{
	mlx_image_t	*img;
	double		zoom;
	double		w_width;
	double		w_height;
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

#endif