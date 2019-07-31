/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:07:40 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 17:10:59 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			swap_b(t_stack **b)
{
	t_stack		*last1;
	t_stack		*last2;
	t_stack		*end;
	
	if (!b || !(*b) || get_len(*b) == 1)
		return (0);
	last1 = take_last(b);
	last2 = take_last(b);
	if (!(end = find_last(*b)))
	{
		*b = last1;
		last1->next = last2;
		last2->next = 0;
	}
	else
	{
		end->next = last1;
		last1->next = last2;
		last2->next = 0;
	}
	return (1);
}

int			push_b(t_stack **a, t_stack **b)
{
	t_stack		*last_a;
	t_stack		*last_b;

	if (!a || !*a)
		return (0);
	last_b = find_last(*b);
	last_a = take_last(a);
	if (!last_b)
	{
		*b = last_a;
	}
	else
	{
		last_b->next = last_a;
		last_a->next = 0;
	}
	return (1);
}

int			rotate_b(t_stack **b)
{
	t_stack		*next;
	t_stack		*first;
	t_stack		*tmp;

	if (!b|| !*b)
		return (0);
	if (get_len(*b) == 1)
		return (1);
	first = (*b);
	next = first->next;
	*b = next;
	first->next = 0;
	tmp = find_last(*b);
	tmp->next = first;
	return (1);
}

int			reverse_rotate_b(t_stack **b)
{
	t_stack		*last;
	t_stack		*first;

	if (!b || !*b)
		return (0);
	if (get_len(*b) == 1)
		return (1);
	first = *b;
	last = take_last(&first);
	*b = last;
	last->next = first;
	return (1);
}
