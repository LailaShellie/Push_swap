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
	int i;
	int tmp;
	int res;
	int j;

	i = 0;
	res = 0;
	tmp = 0;
	j = 0;
	while (i <= 31)
	{
		tmp = (i >= 0 && i <= 7) ? b : tmp;
		tmp = (i >= 8 && i <= 15) ? g : tmp;
		tmp = (i >= 16 && i <= 23) ? r : tmp;
		tmp = (i >= 24 && i <= 31) ? o : tmp;
		j = 0;
		while (j <= 7)
		{
			if (tmp & (1 << j))
				res |= 1 << i;
			++i;
			++j;
		}
	}
	return (res);
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

void		copy_mas(int *mas, t_mlx *mlx)
{
	t_stack		*cur;
	int 		i;

	i = 0;
	cur = mlx->a;
	while (cur)
	{
		mas[i++] = cur->num;
		cur = cur->next;
	}
}

void		bubble_sort(int *mas, int len)
{
	int 	i;
	int 	j;
	int 	tmp;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
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
	copy_mas(mas, mlx);
	bubble_sort(mas, mlx->len);
	set_all(mas, mlx, grad, width);
	free(mas);
	return (0);
}
