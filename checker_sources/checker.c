/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:42:54 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 19:42:55 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		free_mlx(t_mlx *mlx)
{
	free_commands(&mlx->com);
	free_stack(&mlx->a);
	free_stack(&mlx->b);
	free(mlx);
	return (0);
}

void		exec(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		swap_a(a, NOPRINT);
	else if (ft_strcmp("sb", str) == 0)
		swap_b(b, NOPRINT);
	else if (ft_strcmp("ss", str) == 0)
		swap_all(a, b, NOPRINT);
	else if (ft_strcmp("pa", str) == 0)
		push_a(a, b, NOPRINT);
	else if (ft_strcmp("pb", str) == 0)
		push_b(a, b, NOPRINT);
	else if (ft_strcmp("ra", str) == 0)
		rotate_a(a, NOPRINT);
	else if (ft_strcmp("rb", str) == 0)
		rotate_b(b, NOPRINT);
	else if (ft_strcmp("rr", str) == 0)
		rotate_all(a, b, NOPRINT);
	else if (ft_strcmp("rra", str) == 0)
		reverse_rotate_a(a, NOPRINT);
	else if (ft_strcmp("rrb", str) == 0)
		reverse_rotate_b(b, NOPRINT);
	else if (ft_strcmp("rrr", str) == 0)
		reverse_rotate_all(a, b, NOPRINT);
}

int			try_solve(t_mlx *mlx)
{
	t_command		*cur_com;

	if (mlx->flag)
		visualization(mlx);
	cur_com = mlx->com;
	while (cur_com)
	{
		exec(&mlx->a, &mlx->b, cur_com->str);
		cur_com = cur_com->next;
	}
	if (!(is_sorted(mlx->a, mlx->b)))
		return (0);
	return (1);
}

int			check(t_mlx *mlx)
{
	char		*str;

	str = 0;
	while (get_next_line(0, &str))
	{
		if (str && !(check_commands(str)))
		{
			free(str);
			return (error_commands(&mlx->com));
		}
		else if (str)
			make_commands(&mlx->com, str);
		free(str);
		str = 0;
	}
	str ? free(str) : 0;
	if (!(try_solve(mlx)))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (0);
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
			mlx->flag = 1;
		if (argc == 2)
			mlx->a = one_str_input(argv[1]);
		else if (argc > 2)
			mlx->a = multi_str_input(argc - 1 - mlx->flag, &argv[1 + mlx->flag]);
		if (mlx->a)
		{
			check(mlx);
			free_mlx(mlx);
			return (0);
		}
		else
		{
			free_mlx(mlx);
			return (error(0));
		}
	}
	else
		ft_putstr("usage: checker [numbers]\n");
	return (0);
}
