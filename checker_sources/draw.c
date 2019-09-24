/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:02:14 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/23 16:02:15 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		draw_line_b(int step, t_stack *b, t_mlx *mlx)
{
	int 	x;
	int 	y;
	int 	*mas;

	y = HEIGHT - step * (HEIGHT / mlx->len);
	mas = (int *)mlx->img->data;
	while (y > HEIGHT - (step + 1) * (HEIGHT / mlx->len))
	{
		x = WIDTH / 2;
		while (x < WIDTH / 2 + b->width)
		{
			if (!mas[x + (y - 1) * mlx->img->size_line / 4])
				mas[x + (y - 1) * mlx->img->size_line / 4] = b->color;
			++x;
		}
		--y;
	}
}

void		draw_line_a(int step, t_stack *a, t_mlx *mlx)
{
	int 	x;
	int 	y;
	int 	*mas;

	y = HEIGHT - step * (HEIGHT / mlx->len);
	mas = (int *)mlx->img->data;
	while (y > HEIGHT - (step + 1) * (HEIGHT / mlx->len))
	{
		x = 0;
		while (x <= a->width)
		{
			if (!mas[x + (y - 1) * mlx->img->size_line / 4])
				mas[x + (y - 1) * mlx->img->size_line / 4] = a->color;
			++x;
		}
		--y;
	}
}

void		draw_one_line(int step, t_stack *a, t_stack *b, t_mlx *mlx)
{
	if (a)
		draw_line_a(step, a, mlx);
	if (b)
		draw_line_b(step, b, mlx);
}

void		draw(t_mlx *mlx)
{
	t_stack		*a;
	t_stack		*b;
	int 		step;

	step = 0;
	ft_bzero(mlx->img->data, WIDTH * HEIGHT * 4);
	mlx_clear_window(mlx->mlx, mlx->win);
	a = mlx->a;
	b = mlx->b;
	while (a || b)
	{
		draw_one_line(step, a, b, mlx);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		++step;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 5, 3, set_colors(0, 255, 255, 255), ft_itoa(mlx->step));
}


int			make_step(t_mlx *mlx)
{
	if (mlx->cur_com)
	{
		exec(&mlx->a, &mlx->b, mlx->cur_com->str);
		draw(mlx);
		mlx->cur_com = mlx->cur_com->next;
		++mlx->step;
	}
	return (1);
}