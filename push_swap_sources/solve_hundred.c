/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:53:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/05 12:53:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int			get_median(t_stack *a)
{
	int	len;
	int	*mas;
	int ret;

	len = get_len(a);
	if (!(mas = (int *)ft_memalloc(sizeof(int) * len)))
		return (0);
	copy_mas(mas, a);
	bubble_sort(mas, len);
	ret = mas[len >> 1];
	free(mas);
	return (ret);
}

void		push_to_b(t_stack **a, t_stack **b, int parts)
{
	int 		i;
	int 		median;
	int 		len;

	if (!*a)
		return ;
	if (get_len(*a) <= 3)
	{
		solve_three(a, b);
		return ;
	}
	median = get_median(*a);
	len = get_len(*a);
	i = 0;
	while (i <= len)
	{
		if (find_last(*a)->num >= median)
			push_b(a, b, PRINT);
		else
			reverse_rotate_a(a, PRINT);
		++i;
	}
	push_to_b(a, b, parts);
}

void		set_turns(t_stack *a, t_stack *b, t_turns *turns)
{
	t_stack		*cur;
	int			len;

	len = get_len(b);
	cur = b;
	while (cur)
	{
		calculate_turns(a, cur, turns, len);
		cur = cur->next;
	}
}

int			solve_hundred(t_stack **a, t_stack **b)
{
	t_turns		turns;

	push_to_b(a, b, 3);
	while (*b)
	{
		turns.sum = -1;
		set_turns(*a, *b, &turns);
		execute(a, b, &turns);
	}
	if (!is_sorted(*a, *b))
		remove_border(a);
	return (1);
}
