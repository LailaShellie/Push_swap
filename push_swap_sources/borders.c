/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:16:30 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/10 13:16:31 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_pos(t_turns *tmp, int pos, int len)
{
	if (pos == 0)
	{
		tmp->set_by_rr = 1;
		tmp->set_by_r = 0;
	}
	else if (pos == len)
	{
		tmp->set_by_r = 0;
		tmp->set_by_rr = pos;
	}
	else
	{
		tmp->set_by_rr = pos;
		tmp->set_by_r = len - pos;
	}
}

void	calculate_with_borders(t_stack *a, t_turns *tmp, int len)
{
	int bot;
	int pos;

	bot = a->num;
	if (tmp->num < bot)
		pos = calculate_bot(a, tmp, len);
	else
		pos = calculate_top(a, tmp, len);
	calculate_pos(tmp, pos, len);
}

int		calculate_top(t_stack *a, t_turns *tmp, int len)
{
	int pos;
	int mid;

	mid = get_mid(a);
	pos = 0;
	while (a)
	{
		if (a->num == mid)
			break ;
		++pos;
		a = a->next;
	}
	while (a)
	{
		if (a->num < tmp->num)
			break ;
		++pos;
		a = a->next;
	}
	return (pos);
}

int		calculate_bot(t_stack *a, t_turns *tmp, int len)
{
	int pos;

	pos = 0;
	while (a->next)
	{
		if (a->num < tmp->num)
			return (pos);
		if (a->num < a->next->num)
			return (pos + 1);
		++pos;
		a = a->next;
	}
	return (pos);
}

int		get_mid(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			return (stack->next->num);
		stack = stack->next;
	}
	return (stack->num);
}
