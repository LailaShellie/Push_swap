/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors_n_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:25:51 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/23 20:25:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		set_colors(unsigned char o, unsigned char r, \
			unsigned char g, unsigned char b)
{
	return ((int)o << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

int			set_all(int *mas, t_mlx *mlx, float grad, int width)
{
	int		i;
	t_stack	*cur;

	i = -1;
	while (++i < mlx->len)
	{
		cur = mlx->a;
		while (cur)
		{
			if (cur->num == mas[i])
			{
				cur->color = set_colors(0, ((float)i) * grad, 0, 255);
				cur->width = i * width;
			}
			cur = cur->next;
		}
	}
	return (0);
}

int			set_colors_n_len(t_mlx *mlx)
{
	int 	*mas;
	float 	grad;
	int 	width;

	mlx->len = get_len(mlx->a);
	grad = 255 / (float)mlx->len;
	width = WIDTH / (2 * mlx->len);
	if (!(mas = (int *)ft_memalloc(sizeof(int) * mlx->len)))
		return (0);
	copy_mas(mas, mlx->a);
	bubble_sort(mas, mlx->len);
	set_all(mas, mlx, grad, width);
	free(mas);
	return (0);
}
