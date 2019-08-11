/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:25:41 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/10 17:25:42 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		execute_doubles(t_stack **a, t_stack **b, int turns)
{
	int i;

	i = ft_abs(turns);
	while (i != 0)
	{
		if (turns < 0)
			rotate_all(a, b, PRINT);
		else
			reverse_rotate_all(a, b, PRINT);
		--i;
	}
}

void		execute_a(t_stack **a, int turns)
{
	int i;

	i = ft_abs(turns);
	while (i != 0)
	{
		if (turns < 0)
			rotate_a(a, PRINT);
		else
			reverse_rotate_a(a, PRINT);
		--i;
	}
}

void		execute_b(t_stack **b, int turns)
{
	int i;

	i = ft_abs(turns);
	while (i != 0)
	{
		if (turns < 0)
			rotate_b(b, PRINT);
		else
			reverse_rotate_b(b, PRINT);
		--i;
	}
}

void		remove_border(t_stack **a)
{
	int			mid;
	t_stack		*cur;
	int			pos;

	pos = 0;
	cur = *a;
	mid = get_mid(cur);
	while (cur)
	{
		if (cur->num == mid)
			break ;
		++pos;
		cur = cur->next;
	}
	if (pos >= get_len(*a) / 2)
		execute_a(a, pos - get_len(*a));
	else
		execute_a(a, pos);
}

void		execute(t_stack **a, t_stack **b, t_turns *turns)
{
	execute_doubles(a, b, turns->doubles);
	execute_b(b, turns->exec_b);
	execute_a(a, turns->exec_a);
	push_a(a, b, PRINT);
}
