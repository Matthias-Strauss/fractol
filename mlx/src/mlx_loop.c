/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:24:36 by W2Wizard          #+#    #+#             */
/*   Updated: 2024/03/22 14:57:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

static void	mlx_exec_loop_hooks(mlx_t *mlx)
{
	const mlx_ctx_t	*mlxctx = mlx->context;
	mlx_list_t		*lstcpy;
	mlx_hook_t		*hook;

	lstcpy = mlxctx->hooks;
	while (lstcpy && !glfwWindowShouldClose(mlx->window))
	{
		hook = ((mlx_hook_t *)lstcpy->content);
		hook->func(hook->param);
		lstcpy = lstcpy->next;
	}
}

static void	mlx_render_images(mlx_t *mlx)
{
	mlx_ctx_t		*mlxctx;
	mlx_list_t		*imglst;
	mlx_image_t		*image;
	mlx_list_t		*render_queue;
	draw_queue_t	*drawcall;
	mlx_instance_t	*instance;

	mlxctx = mlx->context;
	imglst = mlxctx->images;
	if (sort_queue)
	{
		sort_queue = false;
		mlx_sort_renderqueue(&mlxctx->render_queue);
	}
	// Upload image textures to GPU
	while (imglst)
	{
		if (!(image = imglst->content))
		{
			mlx_error(MLX_INVIMG);
			return ;
		}
		glBindTexture(GL_TEXTURE_2D,
			((mlx_image_ctx_t *)image->context)->texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
		imglst = imglst->next;
	}
	// Execute draw calls
	render_queue = mlxctx->render_queue;
	while (render_queue)
	{
		drawcall = render_queue->content;
		instance = &drawcall->image->instances[drawcall->instanceid];
		if (drawcall && drawcall->image->enabled && instance->enabled)
			mlx_draw_instance(mlx->context, drawcall->image, instance);
		render_queue = render_queue->next;
	}
}

//= Public =//

bool	mlx_loop_hook(mlx_t *mlx, void (*f)(void *), void *param)
{
	mlx_hook_t		*hook;
	mlx_list_t		*lst;
	const mlx_ctx_t	*mlxctx = mlx->context;

	MLX_NONNULL(mlx);
	MLX_NONNULL(f);
	if (!(hook = malloc(sizeof(mlx_hook_t))))
		return (mlx_error(MLX_MEMFAIL));
	if (!(lst = mlx_lstnew(hook)))
	{
		free(hook);
		return (mlx_error(MLX_MEMFAIL));
	}
	hook->func = f;
	hook->param = param;
	mlx_lstadd_back((mlx_list_t **)(&mlxctx->hooks), lst);
	return (true);
}

// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
void	mlx_loop(mlx_t *mlx)
{
	MLX_NONNULL(mlx);
	double start, oldstart = 0;
	while (!glfwWindowShouldClose(mlx->window))
	{
		start = glfwGetTime();
		mlx->delta_time = start - oldstart;
		oldstart = start;
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetWindowSize(mlx->window, &(mlx->width), &(mlx->height));
		if ((mlx->width > 1 || mlx->height > 1))
			mlx_update_matrix(mlx);
		mlx_exec_loop_hooks(mlx);
		mlx_render_images(mlx);
		mlx_flush_batch(mlx->context);
		glfwSwapBuffers(mlx->window);
		glfwPollEvents();
	}
}
