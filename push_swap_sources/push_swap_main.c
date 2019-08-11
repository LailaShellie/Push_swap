/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:52:56 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/30 14:52:59 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solve(t_stack **a)
{
	int			i;
	t_stack		*b;

	b = 0;
	i = get_len(*a);
	if (i <= 3)
		return (solve_three(a, &b));
	else
		return (solve_hundred(a, &b));
}

int		main(int argc, char **argv)
{
	t_stack		*first;

	first = 0;
	if (argc > 1)
	{
		if (argc == 2)
			first = one_str_input(argv[1]);
		else if (argc > 2)
			first = multi_str_input(argc - 1, &argv[1]);
		if (first)
		{
			solve(&first);
			free_stack(&first);
			return (0);
		}
		else
			return (error(0));
	}
	write(1, "\n", 1);
	return (0);
}
