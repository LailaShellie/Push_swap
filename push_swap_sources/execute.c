/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:08:58 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/05 14:08:59 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define FIRST 1
# define SECOND 2

void	execute_doubles(t_stack **a, t_stack **b, int turns, int flag)
{
	int i;

	i = ft_abs(turns);
	while (i)
	{
		if (flag == FIRST)
		{
			if (turns > 0)
				reverse_rotate_all(a, b, PRINT);
			else
				rotate_a(a, PRINT);
		}
		else
		{
			if (turns < 0)
				reverse_rotate_all(a, b, PRINT);
			else
				rotate_a(a, PRINT);
		}
		--i;
	}
}

void	execute_get_in_a(t_stack **a, int turns, int flag)
{
	int i;

	i = ft_abs(turns);
	while (i)
	{
		if (flag == FIRST)
		{
			if (turns > 0)
				reverse_rotate_a(a, PRINT);
			else
				rotate_a(a, PRINT);
		}
		else
		{
			if (turns < 0)
				reverse_rotate_a(a, PRINT);
			else
				rotate_a(a, PRINT);
		}
		--i;
	}
}

void	execute_get_in_b(t_stack **b, int turns)
{
	int i;

	i = ft_abs(turns);
	while (i)
	{
		if (turns > 0)
			reverse_rotate_b(b, PRINT);
		else
			rotate_b(b, PRINT);
		--i;
	}
}

void	execute(t_stack **a, t_stack **b, t_turns *turns)
{
	execute_doubles(a, b, turns->doubles, FIRST);
	execute_get_in_b(b, turns->get_in_b);
	execute_get_in_a(a, turns->set_in_a, FIRST);
	push_a(a, b, PRINT);
	if (turns->place == -1)
		rotate_a(a, PRINT);
	execute_doubles(a, b, turns->doubles, SECOND);
	execute_get_in_a(a, turns->set_in_a, SECOND);
}