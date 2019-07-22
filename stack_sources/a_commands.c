/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:22:47 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 15:22:48 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			swap_a(t_stack **a)
{
	t_stack		*last1;
	t_stack		*last2;
	t_stack		*end;

	end = 0;
	last1 = 0;
	last2 = 0;
	if (!a || !(*a) || get_len(*a) == 1)
		return (0);
	last1 = take_last(a);
	last2 = take_last(a);
	if (!(end = find_last(*a)))
	{
		*a = last1;
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

int			push_a(t_stack **a, t_stack **b)
{
	t_stack		*last_a;
	t_stack		*last_b;

	if (!b || !*b)
		return (0);
	last_a = find_last(*a);
	last_b = take_last(b);
	if (!last_a)
	{
		*a = last_b;
	}
	else
	{
		last_a->next = last_b;
		last_b->next = 0;
	}
	return (1);
}

int			rotate_a(t_stack **a)
{
	t_stack		*next;
	t_stack		*first;
	t_stack		*tmp;

	if (!a || !*a)
		return (0);
	if (get_len(*a) == 1)
		return (1);
	first = (*a);
	next = first->next;
	*a = next;
	first->next = 0;
	tmp = find_last(*a);
	tmp->next = first;
	return (1);
}

int			reverse_rotate_a(t_stack **a)
{
	t_stack		*last;
	t_stack		*first;

	if (!a || !*a)
		return (0);
	if (get_len(*a) == 1)
		return (1);
	first = *a;
	last = take_last(&first);
	*a = last;
	last->next = first;
	return (1);
}