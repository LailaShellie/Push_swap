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

void	calculate_doubles(t_turns *tmp)
{
	int t;

	if (tmp->exec_a > 0 && tmp->exec_b > 0)
	{
		tmp->doubles = tmp->exec_b < tmp->exec_a ? tmp->exec_b : tmp->exec_a;
		t = tmp->exec_b;
		tmp->exec_b -= tmp->exec_b < tmp->exec_a ? tmp->exec_b : tmp->exec_a;
		tmp->exec_a -= tmp->exec_a < t ? tmp->exec_a : t;
	}
	else if (tmp->exec_a < 0 && tmp->exec_b < 0)
	{
		tmp->doubles = tmp->exec_b < tmp->exec_a ? tmp->exec_a : tmp->exec_b;
		t = tmp->exec_b;
		tmp->exec_b -= tmp->exec_b < tmp->exec_a ? tmp->exec_a : t;
		tmp->exec_a -= tmp->exec_a < t ? t : tmp->exec_a;
	}
	tmp->sum = ft_abs(tmp->doubles) + ft_abs(tmp->exec_b) + ft_abs(tmp->exec_a);
}

void	calculate_sum(t_turns *tmp)
{
	tmp->sum = 0;
	tmp->doubles = 0;
	tmp->sum += tmp->set_by_r >= tmp->set_by_rr
			? tmp->set_by_rr : tmp->set_by_r;
	tmp->exec_a = tmp->set_by_r >= tmp->set_by_rr
			? tmp->set_by_rr : -tmp->set_by_r;
	tmp->sum += tmp->get_by_r >= tmp->get_by_rr
			? tmp->get_by_rr : tmp->get_by_r;
	tmp->exec_b = tmp->get_by_r >= tmp->get_by_rr
			? tmp->get_by_rr : -tmp->get_by_r;
	calculate_doubles(tmp);
}

void	calculate_set(t_stack *a, t_turns *tmp)
{
	int		pos;
	int		len;

	len = get_len(a);
	pos = 0;
	if (!is_sorted(a, 0))
	{
		calculate_with_borders(a, tmp, len);
		return ;
	}
	while (a)
	{
		if (a->num < tmp->num)
			break ;
		++pos;
		a = a->next;
	}
	calculate_pos(tmp, pos, len);
}

void	calculate_get(t_stack *b, t_turns *tmp, int len)
{
	int pos;

	pos = get_len(b);
	tmp->get_by_r = pos - 1;
	tmp->get_by_rr = 1 + len - pos;
}

void	calculate_turns(t_stack *a, t_stack *b, t_turns *turns, int len)
{
	t_turns	tmp;

	tmp.num = b->num;
	tmp.doubles = 0;
	calculate_get(b, &tmp, len);
	calculate_set(a, &tmp);
	calculate_sum(&tmp);
	if (turns->sum < 0 || turns->sum >= tmp.sum)
	{
		turns->num = tmp.num;
		turns->exec_a = tmp.exec_a;
		turns->exec_b = tmp.exec_b;
		turns->sum = tmp.sum;
		turns->doubles = tmp.doubles;
	}
}
