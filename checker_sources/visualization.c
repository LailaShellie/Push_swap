/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:40:23 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/23 15:40:24 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	key_event(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free_mlx(mlx);
		exit(0);
	}
	return (0);
}

static int	close_window(void *param)
{
	(void)param;
	exit(0);
}

static void	hooks(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx, make_step, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_hook(mlx->win, 2, 0, key_event, mlx);
	mlx_loop(mlx->mlx);
}

static int	init(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "push_swap")))
		return (0);
	if (!(mlx->img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (0);
	if (!(mlx->img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		return (0);
	if (!(mlx->img->data = mlx_get_data_addr(mlx->img->img, &mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian)))
		return (0);
	mlx->cur_com = mlx->com;
	set_colors_n_len(mlx);
	return (1);
}

void		visualization(t_mlx *mlx)
{
	if (!init(mlx))
		exit(0);
	draw(mlx);
	hooks(mlx);
}
