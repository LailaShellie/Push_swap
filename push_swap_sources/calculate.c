/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:40:55 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/05 13:40:56 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_sum(t_turns *tmp)
{
	tmp->sum = ft_abs(tmp->get_in_b)
			+ 2 * ft_abs(tmp->set_in_a)
			+ ft_abs(tmp->place) + 1;
}

void	calculate_set_in_a(t_stack *a, t_turns *tmp, int num)
{
	int len;
	int pos;

	pos = 0;
	len = get_len(a);
	while (a)
	{
		if (num > a->num)
			break;
		pos++;
		a = a->next;
	}
	if (pos <= len / 2)
	{
		tmp->set_in_a = pos;
		tmp->place = -1;
	}
	else
	{
		tmp->set_in_a = pos - len;
		tmp->place = 0;
	}
	calculate_sum(tmp);
}

void	calculate_get_in_b(t_stack *b, t_turns *tmp, int len)
{
	int pos;

	pos = get_len(b);
	if (pos > len / 2)
		tmp->get_in_b = 1 + (len - pos);
	else
		tmp->get_in_b = 1 - pos;
}

void	calculate_turns(t_stack *a, t_stack *b, t_turns *turns, int len)
{
	t_turns	tmp;

	tmp.num = b->num;
	calculate_get_in_b(b, &tmp, len);
	calculate_set_in_a(a, &tmp, b->num);
	if (turns->sum < 0 || turns->sum > tmp.sum)
	{
		turns->sum = tmp.sum;
		turns->get_in_b = tmp.get_in_b;
		turns->set_in_a = tmp.set_in_a;
		turns->place = tmp.place;
		turns->num = tmp.num;
	}
}