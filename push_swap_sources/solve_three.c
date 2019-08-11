/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:20:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/30 15:20:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define SA_CASE 1
#define RRA_CASE 2
#define RA_CASE 3

int		compare(t_stack **a, t_stack **b)
{
	int top;
	int bot;
	int mid;

	top = find_last(*a)->num;
	mid = ((*a)->next)->num;
	bot = (*a)->num;
	if (top == mid)
		return (SA_CASE);
	else if ((top > mid && mid > bot && bot < top)
	|| (top > mid && mid < bot && bot > top)
	|| (top < mid && mid > bot && bot > top))
		return (SA_CASE);
	else if (top < mid && mid > bot && bot < top)
		return (RRA_CASE);
	else if (top > mid && mid < bot && bot < top)
		return (RA_CASE);
	return (0);
}

int		solve_three(t_stack **a, t_stack **b)
{
	int res;

	res = 0;
	if (is_sorted(*a, *b))
		return (1);
	if ((res = compare(a, b)) == SA_CASE)
		swap_a(a, PRINT);
	if (res == RRA_CASE)
		reverse_rotate_a(a, PRINT);
	if (res == RA_CASE)
		rotate_a(a, PRINT);
	if (!res)
		return (1);
	return (solve_three(a, b));
}
