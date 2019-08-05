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
	int 	i;
	t_stack	*b;

	b = 0;
	i = get_len(*a);
	if (i <= 3)
		return (solve_three(a, &b));
	else
		return (solve_hundred(a, &b));
	return (0);
}

int 	main(int argc, char **argv)
{
	t_stack		*first;
	t_stack		*cur;

	first = 0;
	if (argc != 1)
	{
		if (!(check_input(argc, argv)))
			return (error(0));
		while (--argc)
		{
			if (!first)
			{
				first = new_node(ft_atoi(argv[argc]));
				cur = first;
			}
			else
			{
				cur->next = new_node(ft_atoi(argv[argc]));
				cur = cur->next;
			}
		}
		solve(&first);
		free_stack(&first);
	}
	write(1, "\n", 1);
	return (0);
}